/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:16:37 by tiima             #+#    #+#             */
/*   Updated: 2024/08/16 10:25:15 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**env_to_2d(t_env *env)
{
	char	**env_2d;
	int		i;

	env_2d = malloc(sizeof(char *) * (ft_lstsize2(env) + 1));
	if (!env_2d)
		return (printf("Error while allocate memory for env_2D\n"), NULL);
	i = 0;
	while (env)
	{
		env_2d[i] = ft_strdup(env->key);
		env_2d[i] = ft_strjoin(env_2d[i], "=");
		env_2d[i] = ft_strjoin(env_2d[i], env->value);
		i++;
		env = env->next;
	}
	env_2d[i] = NULL;
	return (env_2d);
}
