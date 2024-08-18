/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:02:17 by aakouhar          #+#    #+#             */
/*   Updated: 2024/08/18 18:14:13 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	size_t	len1;
	char	*newstring;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	newstring = malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstring[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		newstring[len1] = s2[i];
		len1++;
	}
	newstring[len1] = '\0';
	return (fre(s1), fre(s2), newstring);
}

int	here_doc_vs_expand(int i, char *content)
{
	i -= 2;
	if (i > 2)
	{
		if (content[i] == ' ' && content[i - 1] == '<' && content[i - 2] == '<')
			return (1);
	}
	return (0);
}

int	handle_here_doc_expand(int *i, char **str, char *content)
{
	int	start;
	int	end;

	(*i)--;
	start = *i;
	while (content[*i] != ' ')
		(*i)++;
	end = *i;
	*str = ft_join(*str, ft_substr(content, start, end - start));
	return (0);
}

void	handle_ambigous(int start, int end, char **str, char *content)
{
	if (start > 3)
	{
		if ((content[start - 2] == '>' || content[start - 2] == '<')
			&& content[start - 3] != '<')
			*str = ft_join(*str, ft_substr(content, start, end - start));
	}
}

int	handle_last_exit_status(char **str, char c)
{
	char	*s;

	if (c == '?')
	{
		s = ft_itoa(g_data->exit_status);
		*str = ft_strjoin(*str, s);
		fre(s);
	}
	else
	{
		s = g_data->last_arg;
		*str = ft_strjoin(*str, g_data->last_arg);
		fre(s);
		g_data->last_arg = ft_strdup(*str);
	}
	return (0);
}
