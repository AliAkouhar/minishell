/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:15:49 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/17 19:15:50 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	char			op;
	struct s_env	*next;
}					t_env;

/* --env_to_2D.c-- */
char				**env_to_2d(t_env *env);

/* --get_env.c-- */
t_env				*get_env(char **env);
int					ft_lstsize2(t_env *lst);

/* --get_env_utils.c-- */
t_env				*ft_lstnew2(char *name, char *value);
t_env				*ft_lstlast2(t_env *lst);
void				ft_lstadd_back2(t_env **lst, t_env *new);
void				ft_lstdelone2(t_env *lst);
char				*find_key_env(char *key);

#endif