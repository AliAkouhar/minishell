/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:31 by aakouhar          #+#    #+#             */
/*   Updated: 2024/08/16 10:38:28 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_oper(char c)
{
	char	*oper;
	int		i;

	oper = "><|";
	i = -1;
	while (oper[++i])
		if (c == oper[i])
			return (1);
	return (0);
}

int	check_synthax(void)
{
	char	*check;
	int		i;
	int		j;

	check = "*;()&";
	i = -1;
	while (g_data->cmd[++i])
	{
		if (g_data->cmd[i] == '|' && g_data->cmd[i + 1] == ' '
			&& is_oper(g_data->cmd[i + 2]))
			continue ;
		if (is_oper(g_data->cmd[i]) && g_data->cmd[i + 1] == ' '
			&& is_oper(g_data->cmd[i + 2]))
			return (print_error('s', g_data->cmd[i + 2]), -1);
	}
	i = -1;
	while (g_data->cmd[++i])
	{
		j = -1;
		while (check[++j])
			if (g_data->cmd[i] == check[j])
				return (print_error('s', g_data->cmd[i]), -1);
	}
	return (0);
}

int	print_error(char c, char x)
{
	if (c == 's')
	{
		printf("minishell: syntax error near unexpected token `%c'\n", x);
		g_data->exit_status = 2;
	}
	else if (c == 'q')
	{
		printf("unclosed qoute\n");
		g_data->exit_status = 2;
	}
	else if (c == 'n')
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		g_data->exit_status = 2;
	}
	return (g_data->exit_status);
}
