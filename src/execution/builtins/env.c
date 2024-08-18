/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:29:38 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 19:16:57 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_env(void)
{
	t_env	*env;

	env = g_data->my_env;
	while (env)
	{
		if (!ft_strcmp(env->key, "PATH") && ft_lstsize2(g_data->my_env) == 4)
		{
			env = env->next;
			continue ;
		}
		if (env->value)
		{
			ft_putstr_fd(env->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(env->value, 1);
		}
		env = env->next;
	}
}

void	env(char **args)
{
	if (!args[1])
		print_env();
	else
	{
		g_data->exit_status = 127;
		exit_func(ENV_ERR, args[1]);
	}
}
