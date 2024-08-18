/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:38:44 by tiima             #+#    #+#             */
/*   Updated: 2024/08/16 15:51:48 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	*get_if_exist(t_env **env, t_env *new)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, new->key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	lst_addexport(t_env **env, t_env *new)
{
	t_env	*exist;

	if (!new)
		return ;
	exist = get_if_exist(env, new);
	if (exist)
	{
		if (new->op == '=')
		{
			fre(exist->value);
			exist->value = ft_strdup(new->value);
		}
		else if (new->op == '+')
			exist->value = ft_strjoin(exist->value, new->value);
		fre(new->value);
		fre(new->key);
		fre(new);
	}
	else
		ft_lstadd_back2(env, new);
}
