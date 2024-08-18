/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:35:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 19:21:12 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error1(t_error err, char *cmd)
{
	if (err == PIPE_ERR)
		ft_putendl_fd("minishell: error in open pipe", STDERR_FILENO);
	if (err == FORK_ERR)
		ft_putendl_fd("minishell: error in fork", STDERR_FILENO);
	if (err == ACCESS)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
	}
	if (err == CMD_NOT_FOUND)
	{
		if (!ft_strcmp(cmd, "."))
		{
			ft_putendl_fd("minishell: .: filename argument required",
				STDERR_FILENO);
			g_data->exit_status = 2;
			return ;
		}
		g_data->exit_status = 127;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
	}
}

void	ft_error2(t_error err, char *cmd)
{
	if (err == EXECVE)
		ft_putendl_fd("minishell: error in execve", STDERR_FILENO);
	if (err == HOME_NOT_SET)
	{
		g_data->exit_status = 1;
		ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
	}
	if (err == CD_TOO_ARGS)
	{
		g_data->exit_status = 1;
		ft_putendl_fd("minishell: cd : too many arguments", STDERR_FILENO);
	}
	if (err == OLDPWD_NOT_SET)
		ft_putendl_fd("minishell: cd: OLDPWD not set", STDERR_FILENO);
	if (err == CHDIR)
	{
		g_data->exit_status = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	}
	if (err == NUM_ARGS)
		ft_putendl_fd("minishell: no args needed", STDERR_FILENO);
	if (err == EXIT_TOO_ARG)
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
}

void	ft_error3(t_error err, char *cmd)
{
	if (err == ENV_ERR)
	{
		ft_putstr_fd("minishell: env: ’", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd("’: No such file or directory", STDERR_FILENO);
	}
	if (err == EXPORT_ERR)
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	}
	if (err == NO_SUCH_FILE)
	{
		g_data->exit_status = 1;
		(ft_putstr_fd("minishell: ", 2), ft_putstr_fd(cmd, 2));
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	}
	if (err == HER_DOC_ERR)
	{
		ft_putstr_fd("> minishell: warning: ", STDERR_FILENO);
		ft_putstr_fd("here-document delimited by end-of-file (wanted `",
			STDERR_FILENO);
		(ft_putstr_fd(cmd, STDERR_FILENO), ft_putendl_fd("')", STDERR_FILENO));
	}
}

void	ft_error4(t_error err, char *cmd)
{
	if (err == PERR_DENIED)
	{
		g_data->exit_status = 126;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
	}
	if (err == AMBIGUOUS)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": ambiguous redirect", STDERR_FILENO);
	}
	if (err == DIR_ERR)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": Is a directory", STDERR_FILENO);
	}
	if (err == NUMERIC_ARGS)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
}

void	exit_func(t_error err, char *cmd)
{
	ft_error1(err, cmd);
	ft_error2(err, cmd);
	ft_error3(err, cmd);
	ft_error4(err, cmd);
}
