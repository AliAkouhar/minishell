/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:40:44 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/16 15:04:18 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	*ft_lstnew2(char *name, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_env	*ft_lstlast2(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back2(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast2(*lst);
	tmp->next = new;
}

void	ft_lstdelone2(t_env *lst)
{
	if (!lst)
		return ;
	fre(lst->key);
	fre(lst->value);
	fre(lst);
}

char	*find_key_env(char *key)
{
	t_env	*tmp;

	tmp = g_data->my_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			fre(key);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	fre(key);
	return (NULL);
}
