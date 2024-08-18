/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:16:03 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 18:36:06 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* -------------------------------PARCING--------------------------------*/
void	split_tokens(t_list **p_tokens);
t_list	*ft_fill_tokens(void);
int		fill_mini_tokens(t_list *list);
int		print_error(char c, char x);
int		check_synthax(void);
void	ft_free_struct(t_list **list);
void	solve_pipe_problem(char *str);
void	solve_between_quote(void);
int		check_synthax_error(char *str);
int		is_all_space(char *str);
void	check_pipe(char *str, char *check);
t_list	*ft_filtre(void);
int		filtre_1(void);
char	*new_cmd(void);
char	*ft_strjoin_char(char *s1, char c);
void	return_special_char(t_list *list);
int		fill_cmd_args(t_list *list);
int		handle_here_doc(t_list *tmp, int i);
int		last_here_doc(char **args, int i);
void	handle_input_output(t_list *tmp, char **args, int i);
void	ft_lstadd_back_redir(t_redir **redir, t_redir *new);
t_redir	*ft_lstlast_redir(t_redir *redir);
t_redir	*ft_lstnew_redir(char *name, int flag);
void	ft_lstclear_redir(t_redir **lst);
int		ft_lstsize_redir(t_redir *redir);
int		expand(int *i, char **str, char *content);
void	join_single_quote(int *i, char **str, char *content);
void	handle_expand(t_list *list);
int		handle_here_doc_expand(int *i, char **str, char *content);
int		here_doc_vs_expand(int i, char *content);
void	remove_quotes(t_list *list);
int		init_program(char **av, int ac, char **envp);
int		is_special(char c, int flag);
void	solve_here_doc(int *i, char **str);
void	handle_ambigous(int start, int end, char **str, char *content);
char	*remove_quote_from_lim(char *name, int *lim_flag);
int		handle_last_exit_status(char **str, char c);
void	ft_norm(t_list *list, int i, int *j, char **str);
char	*generate_filename(char *arr);
char	*filename(char *file);
void	fre(void *p);
char	*ft_join(char *s1, char *s2);
void	ctrl_c(t_redir *node);
void	ft_handler(int x);
int		free_env_ctrl_d(t_env **env);
void	handle_special_char(char *str);

#endif