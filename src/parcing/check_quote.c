/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:42:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 18:52:27 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_quote(char *token, int *j, char **str)
{
	int		start;
	int		end;
	char	*substr;

	(*j)++;
	start = *j;
	while (token[*j] && token[*j] != '\'' && token[*j] != '"')
		(*j)++;
	end = *j;
	substr = ft_substr(token, start, end - start);
	if (*str)
		*str = ft_join(*str, substr);
	else
		*str = substr;
}

void	ft_norm(t_list *list, int i, int *j, char **str)
{
	if (list->mini_tokens[i][*j] == '\'' || list->mini_tokens[i][*j] == '"')
		handle_quote(list->mini_tokens[i], j, str);
	else
		*str = ft_strjoin_char(*str, list->mini_tokens[i][*j]);
}

void	remove_quotes(t_list *tmp)
{
	int		i;
	int		j;
	char	*str;
	t_list	*list;

	list = tmp;
	while (list)
	{
		i = -1;
		while (list->mini_tokens[++i])
		{
			j = -1;
			str = NULL;
			while (list->mini_tokens[i][++j])
				ft_norm(list, i, &j, &str);
			fre(list->mini_tokens[i]);
			list->mini_tokens[i] = ft_strdup(str);
			fre(str);
			if (!ft_strcmp(list->mini_tokens[i], "<<"))
				i++;
		}
		list = list->next;
	}
}

char	*remove_quote_from_lim(char *name, int *lim_flag)
{
	char	*str;
	int		i;

	str = NULL;
	i = -1;
	*lim_flag = 1;
	while (name[++i])
	{
		if (name[i] == '"' || name[i] == '\'')
			continue ;
		else
			str = ft_strjoin_char(str, name[i]);
	}
	i = -1;
	while (str[++i])
		if (is_special(str[i] * (-1), 0) || str[i] * (-1) == '\'' || str[i]
			* (-1) == '"')
			str[i] *= -1;
	free(name);
	return (str);
}
