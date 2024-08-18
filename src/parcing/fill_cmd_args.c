/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:38:00 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 15:04:18 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_args(char **mini_tokens)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (mini_tokens[i])
	{
		if (mini_tokens[i][0] == '>' || mini_tokens[i][0] == '<')
			i += 2;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	handle_args_and_redir(t_list *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp->mini_tokens[i])
	{
		if (tmp->mini_tokens[i][0] == '>' || tmp->mini_tokens[i][0] == '<')
		{
			if (!handle_here_doc(tmp, i))
				return (0);
			i += 2;
		}
		else
		{
			tmp->cmd_args[j] = ft_strdup(tmp->mini_tokens[i]);
			j++;
			i++;
		}
	}
	return (1);
}

int	fill_cmd_args(t_list *list)
{
	int		count;
	t_list	*tmp;
	int		i;

	tmp = list;
	i = -1;
	while (tmp)
	{
		count = count_args(tmp->mini_tokens);
		tmp->cmd_args = malloc(sizeof(char *) * (count + 1));
		if (!tmp->cmd_args)
			return (printf("Error while allocating tmp->cmd_args\n"), 0);
		tmp->cmd_args[count] = NULL;
		if (!handle_args_and_redir(tmp))
			return (ft_free_struct(&list), 0);
		tmp = tmp->next;
	}
	return (1);
}
