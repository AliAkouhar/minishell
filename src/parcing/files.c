/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:17:20 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 18:53:14 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_here_doc(t_list *tmp, int i)
{
	t_redir	*new;

	if (g_data->here_doc_nbr > 16)
	{
		printf("minishell: maximum here-document count exceeded\n");
		g_data->exit_status = 2;
		exit(2);
	}
	if (!ft_strcmp(tmp->mini_tokens[i], "<<"))
	{
		new = ft_lstnew_redir(ft_strdup(tmp->mini_tokens[i + 1]), 3);
		if (!new)
			return (0);
		ft_lstadd_back_redir(&tmp->files, new);
		g_data->here_doc_nbr++;
	}
	else if (((tmp->mini_tokens[i][0] == '>' || tmp->mini_tokens[i][0] == '<')
			&& !tmp->mini_tokens[i][1]) || !ft_strcmp(tmp->mini_tokens[i],
			">>"))
		handle_input_output(tmp, tmp->mini_tokens, i);
	return (1);
}

void	handle_input_output(t_list *tmp, char **args, int i)
{
	t_redir	*new_redir;

	if (args[i][0] == '>')
	{
		if ((args[i][0] == '>' && !args[i][1]))
			new_redir = ft_lstnew_redir(args[i + 1], 1);
		else
			new_redir = ft_lstnew_redir(args[i + 1], 2);
		ft_lstadd_back_redir(&tmp->files, new_redir);
	}
	else if (args[i][0] == '<' && !args[i][1])
	{
		new_redir = ft_lstnew_redir(args[i + 1], 0);
		ft_lstadd_back_redir(&tmp->files, new_redir);
	}
}

void	solve_here_doc(int *i, char **str)
{
	if (g_data->cmd[*i] == '<' || g_data->cmd[*i] == '>')
	{
		if ((*i) > 0 && g_data->cmd[(*i) - 1] != ' ')
			*str = ft_strjoin_char(*str, ' ');
		*str = ft_strjoin_char(*str, g_data->cmd[*i]);
		if (g_data->cmd[*i + 1] == g_data->cmd[*i])
		{
			(*i)++;
			*str = ft_strjoin_char(*str, g_data->cmd[*i]);
		}
		if (g_data->cmd[*i + 1] != ' ' && g_data->cmd[*i + 1] != '\0')
			*str = ft_strjoin_char(*str, ' ');
	}
	else
		*str = ft_strjoin_char(*str, g_data->cmd[*i]);
	(*i)++;
}
