/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:41:44 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 18:27:20 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_expand(int *i, char **str, char *line)
{
	int	start;
	int	end;

	start = *i;
	while (ft_isalnum(line[*i]))
		(*i)++;
	end = *i;
	*str = ft_strjoin(*str, find_key_env(ft_substr(line, start, end - start)));
	(*i)--;
}

char	*expand_in_here_doc(char *line)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	while (line[++i])
	{
		if (line[i] == '$')
		{
			i++;
			ft_expand(&i, &str, line);
		}
		else
			str = ft_strjoin_char(str, line[i]);
	}
	fre(line);
	return (str);
}

void	sig_here_doc(int num)
{
	(void)num;
	g_data->signal = 0;
	rl_replace_line("", 0);
	rl_on_new_line();
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_done = 1;
	g_data->exit_status = 130;
}

void	ctrl_c(t_redir *node)
{
	unlink(node->filename);
	fre(node->filename);
	fre(node->lim);
	fre(node);
}

int	here_doc(t_redir *node)
{
	char	*line;
	int		fd;

	node->filename = generate_filename("0123456789abcdef");
	fd = open(node->filename, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	while (1)
	{
		signal(SIGINT, sig_here_doc);
		line = readline("> ");
		if (!g_data->signal)
			return (g_data->signal = 1, ctrl_c(node), close(fd), fre(line), 0);
		if (!line)
			return (fre(line), exit_func(HER_DOC_ERR, node->lim), close(fd), 1);
		if (!ft_strcmp(line, node->lim))
			return (fre(line), close(fd), 1);
		if (ft_strchr(line, '$') && node->lim_flag != 1)
			line = expand_in_here_doc(line);
		ft_putendl_fd(line, fd);
		fre(line);
	}
	return (1);
}
