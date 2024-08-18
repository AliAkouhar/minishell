/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/08/18 18:35:49 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	*g_data = NULL;

int	init_program(char **av, int ac, char **envp)
{
	g_data = malloc(sizeof(t_global));
	g_data->last_arg = ft_strdup("]");
	g_data->path = ft_strdup("/usr/local/sbin:/usr/local/bin:");
	g_data->path = ft_strjoin(g_data->path, "/usr/sbin:/usr/bin:/sbin:/bin");
	g_data->my_env = get_env(envp);
	g_data->exit_status = 0;
	g_data->here_doc_nbr = 0;
	g_data->signal = 1;
	g_data->pwd = getcwd(NULL, 0);
	if (ac != 1)
	{
		exit_func(NUM_ARGS, av[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_handler(int x)
{
	if (x == SIGINT && g_data->signal == 1)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_data->exit_status = 130;
	}
}

void	ft_after(int num)
{
	if (num == SIGINT)
		g_data->exit_status = 130;
}

int	main(int ac, char **av, char **env)
{
	t_list	*list;

	init_program(av, ac, env);
	while (1)
	{
		signal(SIGINT, &ft_handler);
		signal(SIGQUIT, SIG_IGN);
		g_data->cmd = readline("minishell$> ");
		signal(SIGINT, &ft_after);
		if (!g_data->cmd)
			return (printf("exit\n"), free_env_ctrl_d(&g_data->my_env));
		add_history(g_data->cmd);
		list = ft_filtre();
		if (!list)
		{
			fre(g_data->cmd);
			continue ;
		}
		fre(g_data->cmd);
		execution(list);
		ft_free_struct(&list);
		g_data->here_doc_nbr = 0;
	}
	return (g_data->exit_status);
}
