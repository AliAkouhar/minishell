/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/08/16 10:40:49 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	filtre_1(void)
{
	int	i;

	i = 0;
	g_data->d_quote = false;
	g_data->s_quote = false;
	while (g_data->cmd[i])
	{
		if ((g_data->cmd[i] == '|' && g_data->cmd[i + 1] == '\0')
			|| g_data->cmd[0] == '|')
			return (print_error('s', g_data->cmd[i]));
		if (g_data->cmd[i] == '"' && !g_data->s_quote)
			g_data->d_quote = !g_data->d_quote;
		else if (g_data->cmd[i] == '\'' && !g_data->d_quote)
			g_data->s_quote = !g_data->s_quote;
		if ((g_data->cmd[i] == '|' || g_data->cmd[i] == '>'
				|| g_data->cmd[i] == '<') && !g_data->cmd[i + 1])
			return (print_error('n', 'n'));
		i++;
	}
	if (g_data->s_quote == true || g_data->d_quote == true)
		return (print_error('q', 'q'));
	return (0);
}

int	is_special(char c, int flag)
{
	int		i;
	char	*check;

	check = " <|>;&*(){}#[]\t";
	if (flag == 1 && c == '"')
		return (1);
	else if (flag == 2 && c == '\'')
		return (1);
	else if (flag == 3 && (c == '\'' || c == '"'))
		return (1);
	i = -1;
	while (check[++i])
		if (check[i] == c)
			return (1);
	return (0);
}

void	solve_between_quote(void)
{
	int	i;
	int	flag;

	g_data->d_quote = false;
	g_data->s_quote = false;
	i = -1;
	while (g_data->cmd[++i])
	{
		if (g_data->cmd[i] == '"' && !g_data->s_quote)
		{
			g_data->d_quote = !g_data->d_quote;
			flag = 2;
		}
		else if (g_data->cmd[i] == '\'' && !g_data->d_quote)
		{
			g_data->s_quote = !g_data->s_quote;
			flag = 1;
		}
		if ((g_data->d_quote || g_data->s_quote) && is_special(g_data->cmd[i],
				flag))
			g_data->cmd[i] *= -1;
	}
}

char	*new_cmd(void)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	if (!g_data->cmd)
		return (NULL);
	while (g_data->cmd[++i])
	{
		if (g_data->cmd[i] == ' ' && g_data->cmd[i + 1] == ' ')
			continue ;
		if ((g_data->cmd[i] == '>' || g_data->cmd[i] == '<'))
			solve_here_doc(&i, &str);
		str = ft_strjoin_char(str, g_data->cmd[i]);
	}
	fre(g_data->cmd);
	return (str);
}

t_list	*ft_filtre(void)
{
	t_list	*list;
	char	*tmp;

	tmp = g_data->cmd;
	g_data->cmd = ft_strtrim(g_data->cmd, " \t");
	fre(tmp);
	if (filtre_1())
		return (NULL);
	solve_between_quote();
	g_data->cmd = new_cmd();
	if (!g_data->cmd)
		return (NULL);
	if (check_synthax())
		return (NULL);
	list = ft_fill_tokens();
	return (list);
}
