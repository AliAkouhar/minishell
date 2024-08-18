/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:52:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/16 10:33:12 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtins(char *command)
{
	return (!ft_strcmp(command, "cd") || !ft_strcmp(command, "echo")
		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "export")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "env")
		|| !ft_strcmp(command, "exit"));
}

void	execute_builtins(t_list *list)
{
	g_data->exit_status = 0;
	if (ft_strcmp(list->cmd_args[0], "cd") == 0)
		cd(list->cmd_args);
	else if (ft_strcmp(list->cmd_args[0], "echo") == 0)
		echo(list);
	else if (ft_strcmp(list->cmd_args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(list->cmd_args[0], "export") == 0)
		export(list->cmd_args);
	else if (ft_strcmp(list->cmd_args[0], "unset") == 0)
		unset(list->cmd_args);
	else if (ft_strcmp(list->cmd_args[0], "env") == 0)
		env(list->cmd_args);
	else if (ft_strcmp(list->cmd_args[0], "exit") == 0)
		ft_exit(list->cmd_args);
}
