/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/08/18 18:22:01 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_special_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '"' || str[i] == '\'')
			str[i] *= -1;
	}
}

int	fill_mini_tokens(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->mini_tokens = ft_split(tmp->content, ' ');
		fre(tmp->content);
		tmp->cmd_args = NULL;
		tmp->files = NULL;
		tmp = tmp->next;
	}
	remove_quotes(list);
	if (!fill_cmd_args(list))
		return (0);
	return (1);
}

t_list	*ft_fill_tokens(void)
{
	char	**str;
	t_list	*list;
	t_list	*new;
	int		i;

	list = NULL;
	str = ft_split(g_data->cmd, '|');
	i = -1;
	while (str[++i])
	{
		new = ft_lstnew(str[i]);
		if (!new)
			printf("Failed to create the node\n");
		new->mini_tokens = NULL;
		ft_lstadd_back(&list, new);
	}
	fre(str);
	handle_expand(list);
	if (!list->content)
		return (fre(list), NULL);
	if (!fill_mini_tokens(list))
		return (NULL);
	return_special_char(list);
	return (list);
}

void	return_from_files(t_list *list, int x, t_redir *files)
{
	t_redir	*f;
	int		i;

	if (ft_lstsize(list) == 1 && list->cmd_args[0])
	{
		fre(g_data->last_arg);
		g_data->last_arg = ft_strdup(list->cmd_args[x - 1]);
	}
	f = files;
	while (f)
	{
		i = -1;
		while (f->filename[++i])
		{
			if (is_special(f->filename[i] * (-1), 0) || f->filename[i]
				* (-1) == '\'' || f->filename[i] * (-1) == '"')
				f->filename[i] *= -1;
		}
		f = f->next;
	}
}

void	return_special_char(t_list *list)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->cmd_args)
		{
			i = -1;
			while (tmp->cmd_args[++i])
			{
				j = -1;
				while (tmp->cmd_args[i][++j])
					if (is_special(tmp->cmd_args[i][j] * (-1), 3))
						tmp->cmd_args[i][j] *= -1;
			}
		}
		tmp = tmp->next;
	}
	return_from_files(list, i, list->files);
}
