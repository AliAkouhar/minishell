/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:29:30 by aakouhar          #+#    #+#             */
/*   Updated: 2024/08/18 18:14:26 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	join_single_quote(int *i, char **str, char *content)
{
	if (content[*i] == '\'')
	{
		*str = ft_strjoin_char(*str, '\'');
		(*i)++;
	}
	while (content[*i] && content[*i] != '\'')
	{
		*str = ft_strjoin_char(*str, content[*i]);
		(*i)++;
	}
	if (content[*i] == '\'')
		*str = ft_strjoin_char(*str, '\'');
}

int	expand(int *i, char **str, char *content)
{
	int		start;
	int		end;
	char	*s;

	(*i)++;
	if (here_doc_vs_expand(*i, content))
		return (handle_here_doc_expand(i, str, content));
	if (content[*i] == '?' || content[*i] == '_')
		return (handle_last_exit_status(str, content[*i]));
	start = *i;
	while (ft_isalnum(content[*i]))
		(*i)++;
	end = *i;
	s = find_key_env(ft_substr(content, start, end - start));
	if (!s)
		handle_ambigous(start - 1, end, str, content);
	else
	{
		handle_special_char(s);
		*str = ft_strjoin(*str, s);
	}
	(*i)--;
	return (0);
}

void	handle_expand(t_list *list)
{
	t_list	*tmp;
	int		i;
	char	*str;

	tmp = list;
	while (tmp)
	{
		i = -1;
		str = NULL;
		while (tmp->content[++i])
		{
			if (tmp->content[i] == '\'')
				join_single_quote(&i, &str, tmp->content);
			else if (tmp->content[i] == '$' && (ft_isalnum(tmp->content[i + 1])
					|| tmp->content[i + 1] == '?' || tmp->content[i
						+ 1] == '_'))
				expand(&i, &str, tmp->content);
			else
				str = ft_strjoin_char(str, tmp->content[i]);
		}
		fre(tmp->content);
		tmp->content = str;
		tmp = tmp->next;
	}
}
