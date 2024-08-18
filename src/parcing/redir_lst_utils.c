/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:00:38 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 19:22:19 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstclear_redir(t_redir **lst)
{
	t_redir	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		fre((*lst)->filename);
		fre(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_redir	*ft_lstnew_redir(char *name, int flag)
{
	t_redir	*node;

	node = malloc(sizeof(t_redir));
	if (flag == 0 || flag == 1 || flag == 2)
	{
		if (flag == 1)
			node->type = OUTPUT;
		else if (flag == 2)
			node->type = APPEND;
		else
			node->type = INPUT;
		node->filename = ft_strdup(name);
	}
	else if (flag == 3)
	{
		node->type = HERE_DOC;
		if (ft_strchr(name, '"') || ft_strchr(name, '\''))
			name = remove_quote_from_lim(name, &node->lim_flag);
		node->lim = ft_strdup(name);
		fre(name);
		if (!here_doc(node))
			return (NULL);
	}
	return (node->next = NULL, node);
}

t_redir	*ft_lstlast_redir(t_redir *redir)
{
	if (!redir)
		return (NULL);
	while (redir->next != NULL)
		redir = redir->next;
	return (redir);
}

int	ft_lstsize_redir(t_redir *redir)
{
	int	counter;

	counter = 0;
	while (redir != NULL)
	{
		counter++;
		redir = redir->next;
	}
	return (counter);
}

void	ft_lstadd_back_redir(t_redir **redir, t_redir *new)
{
	t_redir	*tmp;

	if (!new)
		return ;
	if (!redir || !(*redir))
	{
		*redir = new;
		return ;
	}
	tmp = ft_lstlast_redir(*redir);
	tmp->next = new;
}
