/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_non_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:10:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 10:17:00 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_existence(char *cmd)
{
	DIR	*dir;

	dir = opendir(cmd);
	if (dir)
	{
		g_data->exit_status = 126;
		exit_func(DIR_ERR, cmd);
		closedir(dir);
		exit(g_data->exit_status);
	}
	if (access(cmd, F_OK) == -1)
	{
		exit_func(NO_SUCH_FILE, cmd);
		g_data->exit_status = 127;
		exit(g_data->exit_status);
	}
	if (access(cmd, X_OK) == -1)
	{
		exit_func(PERR_DENIED, cmd);
		exit(g_data->exit_status);
	}
	return (0);
}

char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	if (!cmd || !cmd[0])
		return (NULL);
	if (ft_strchr(cmd, '/'))
		if (!check_existence(cmd))
			return (cmd);
	if (!paths)
	{
		exit_func(NO_SUCH_FILE, cmd);
		g_data->exit_status = 127;
		exit(g_data->exit_status);
	}
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (!access(cmd_path, X_OK))
			return (cmd_path);
		fre(cmd_path);
	}
	return (NULL);
}

char	*find_path(t_env *my_env)
{
	t_env	*env;

	env = my_env;
	while (env)
	{
		if (!ft_strcmp(env->key, "PATH"))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

void	ft_execve(t_list *list)
{
	char	*all_path;
	char	**paths;
	char	**cmd_args;
	char	*cmd_path;
	char	**arr_env;

	all_path = find_path(g_data->my_env);
	paths = ft_split(all_path, ':');
	fre(all_path);
	if (ft_strchr(list->cmd_args[0], '\n'))
		cmd_args = ft_split(list->cmd_args[0], '\n');
	else
		cmd_args = list->cmd_args;
	cmd_path = get_cmd_path(cmd_args[0], paths);
	if (!cmd_path || !ft_strcmp(cmd_args[0], ".") || !ft_strcmp(cmd_args[0],
			".."))
	{
		exit_func(CMD_NOT_FOUND, cmd_args[0]);
		free_2d(cmd_args);
		exit(127);
	}
	arr_env = env_to_2d(g_data->my_env);
	execve(cmd_path, cmd_args, arr_env);
	(free_2d(cmd_args), fre(cmd_path), free_2d(arr_env));
	exit_func(EXECVE, NULL);
}
