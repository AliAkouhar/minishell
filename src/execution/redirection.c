/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:55:06 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/14 12:14:33 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_there_outfile(t_redir *files)
{
	t_redir	*f;

	f = files;
	while (f)
	{
		if (f->type == OUTPUT || f->type == APPEND)
			return (1);
		f = f->next;
	}
	return (0);
}

void	dup_out_pipe(t_list *list)
{
	if (list->next)
	{
		if (!is_there_outfile(list->files))
		{
			dup2(list->pipe_fd[1], STDOUT_FILENO);
			close_pipe(list);
		}
	}
}

void	restore_stdio(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
}

void	save_stdio(int *saved_stdin, int *saved_stdout)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdin == -1 || *saved_stdout == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}
}
