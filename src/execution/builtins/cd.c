/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:40:55 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 18:01:34 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*find_key_env2(char *key)
{
	t_env	*tmp;

	tmp = g_data->my_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	set_value_env(char *key, char *value)
{
	t_env	*env;

	env = g_data->my_env;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			if (env->value)
			{
				fre(env->value);
				env->value = NULL;
			}
			env->value = ft_strjoin2(env->value, value);
			return ;
		}
		env = env->next;
	}
}

char	*new_cwd_env(char *str)
{
	char	*path;

	path = NULL;
	if (!str || str[0] == '~')
	{
		path = find_key_env(ft_strdup("HOME"));
		if (!path)
		{
			exit_func(HOME_NOT_SET, NULL);
			return (NULL);
		}
	}
	else if (str[0] == '-')
	{
		path = find_key_env(ft_strdup("OLDPWD"));
		if (!path)
		{
			g_data->exit_status = 1;
			exit_func(OLDPWD_NOT_SET, NULL);
			return (NULL);
		}
	}
	if (!path)
		path = str;
	return (path);
}

void	handle_path(char *str)
{
	char	*cwd;
	char	*new_cwd;

	new_cwd = new_cwd_env(str);
	if (!new_cwd)
		return ;
	if (new_cwd && chdir(new_cwd) == -1)
		exit_func(CHDIR, new_cwd);
	set_value_env("OLDPWD", find_key_env2(g_data->pwd));
	cwd = getcwd(NULL, 0);
	set_value_env("PWD", cwd);
	if (g_data->pwd)
		fre(g_data->pwd);
	g_data->pwd = ft_strdup(cwd);
	if (cwd)
		fre(cwd);
	if (str && !ft_strcmp(str, "-"))
		pwd();
}

void	cd(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		;
	if (i > 2)
	{
		exit_func(CD_TOO_ARGS, NULL);
		return ;
	}
	if (!args[1])
		args[1] = NULL;
	handle_path(args[1]);
}
