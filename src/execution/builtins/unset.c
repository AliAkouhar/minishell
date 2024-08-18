/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:41:31 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/16 09:45:35 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	unset_var(t_env **env, char *key)
{
	t_env	*deleted_one;
	t_env	*previous;

	if (!ft_strcmp((*env)->key, key))
	{
		deleted_one = *env;
		*env = (*env)->next;
		ft_lstdelone2(deleted_one);
		return ;
	}
	deleted_one = *env;
	while (deleted_one->next)
	{
		previous = deleted_one;
		if (!ft_strcmp(deleted_one->next->key, key))
		{
			deleted_one = deleted_one->next;
			previous->next = deleted_one->next;
			ft_lstdelone2(deleted_one);
			break ;
		}
		deleted_one = deleted_one->next;
	}
}

void	unset(char **args)
{
	int	i;

	i = 1;
	if (!args[i])
		return ;
	while (args[i])
	{
		if (args[i][0] == '_' && !args[i][1])
		{
			i++;
			continue ;
		}
		if (!ft_is_alphanum(args[i]))
		{
			g_data->exit_status = 1;
			i++;
			continue ;
		}
		unset_var(&g_data->my_env, args[i]);
		i++;
	}
}
