/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:54:23 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 18:36:18 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fre(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return ;
}

void	free_2d(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		fre(str[i]);
	fre(str);
}

void	ft_free_struct(t_list **list)
{
	t_redir	*tmp;
	t_list	*list_tmp;

	while (*list)
	{
		list_tmp = (*list)->next;
		if ((*list)->mini_tokens)
			free_2d((*list)->mini_tokens);
		if ((*list)->cmd_args)
			free_2d((*list)->cmd_args);
		while ((*list)->files)
		{
			tmp = (*list)->files->next;
			if ((*list)->files->type == HERE_DOC)
			{
				unlink((*list)->files->filename);
				fre((*list)->files->lim);
			}
			fre((*list)->files->filename);
			fre((*list)->files);
			(*list)->files = tmp;
		}
		fre(*list);
		*list = list_tmp;
	}
}

int	free_env_ctrl_d(t_env **env)
{
	int		i;
	t_env	*tmp;

	fre(g_data->last_arg);
	fre(g_data->pwd);
	fre(g_data->cmd);
	fre(g_data->path);
	while (*env)
	{
		tmp = (*env)->next;
		fre((*env)->key);
		fre((*env)->value);
		fre(*env);
		*env = tmp;
	}
	i = g_data->exit_status;
	fre(g_data);
	return (i);
}
