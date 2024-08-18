/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:15:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 19:16:32 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "env.h"
# include "execution.h"
# include "parcing.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>

typedef struct s_global
{
	t_env		*my_env;
	char		*cmd;
	char		*pwd;
	int			exit_status;
	int			here_doc_nbr;
	int			signal;
	bool		d_quote;
	bool		s_quote;
	char		*last_arg;
	char		*path;
}				t_global;

extern t_global	*g_data;

#endif