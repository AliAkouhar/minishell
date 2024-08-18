/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:09:46 by aakouhar          #+#    #+#             */
/*   Updated: 2024/08/16 11:57:27 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_lstsize2(t_env *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

void	handle_env_i(t_env **head)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_lstadd_back2(head, ft_lstnew2("PWD", pwd));
	ft_lstadd_back2(head, ft_lstnew2("PATH", g_data->path));
	ft_lstadd_back2(head, ft_lstnew2("SHLVL", "1"));
	ft_lstadd_back2(head, ft_lstnew2("_",
			"/nfs/homes/fbazaz/Desktop/minishell/./minishell"));
	fre(pwd);
}

t_env	*get_env(char **env)
{
	t_env	*head;
	t_env	*new;
	char	*str;
	int		i;

	i = 0;
	head = NULL;
	if (!env[0])
		handle_env_i(&head);
	while (env[i])
	{
		str = ft_strchr(env[i], '=');
		if (str)
		{
			*str = '\0';
			new = ft_lstnew2(env[i], str + 1);
			*str = '=';
			ft_lstadd_back2(&head, new);
		}
		i++;
	}
	return (head);
}
