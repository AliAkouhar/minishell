/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 17:43:52 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_after2(int num)
{
	if (num == SIGINT)
		g_data->exit_status = 130;
}

int	execute_cmd(t_list *list)
{
	open_pipes(list->pipe_fd);
	list->pid = fork_process();
	if (!list->pid)
	{
		signal(SIGINT, &ft_after2);
		signal(SIGQUIT, SIG_DFL);
		if (open_files(list))
			exit(1);
		if (!list->cmd_args[0])
			exit(0);
		dup_out_pipe(list);
		if (is_builtins(list->cmd_args[0]))
		{
			execute_builtins(list);
			exit(0);
		}
		else
			ft_execve(list);
	}
	else
	{
		dup2(list->pipe_fd[0], STDIN_FILENO);
		close_pipe(list);
	}
	return (0);
}

void	run_execution(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (execute_cmd(tmp))
		{
			tmp = tmp->next;
			continue ;
		}
		tmp = tmp->next;
	}
	wait_child(list);
}

void	execution(t_list *list)
{
	int	stdin;
	int	stdout;

	save_stdio(&stdin, &stdout);
	if (ft_lstsize(list) == 1 && list->cmd_args[0])
	{
		if (is_builtins(list->cmd_args[0]))
		{
			if (open_files(list))
			{
				restore_stdio(stdin, stdout);
				return ;
			}
			execute_builtins(list);
			restore_stdio(stdin, stdout);
			return ;
		}
	}
	run_execution(list);
	restore_stdio(stdin, stdout);
}
