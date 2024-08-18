/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:12:30 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 18:59:13 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	open_pipes(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		exit_func(PIPE_ERR, NULL);
		exit(EXIT_FAILURE);
	}
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		exit_func(FORK_ERR, NULL);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	close_pipe(t_list *list)
{
	if (list->pipe_fd[0] != 0)
		close(list->pipe_fd[0]);
	if (list->pipe_fd[1] != 1)
		close(list->pipe_fd[1]);
}

void	wait_child(t_list *list)
{
	int	status;
	int	sig;

	waitpid((ft_lstlast(list))->pid, &status, 0);
	if (WIFEXITED(status))
		g_data->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
		{
			g_data->exit_status = 130;
			printf("\n");
		}
		else if (sig == SIGQUIT)
		{
			g_data->exit_status = 131;
			ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
		}
		else
			g_data->exit_status = sig + 128;
	}
	while (wait(NULL) != -1)
		;
}
