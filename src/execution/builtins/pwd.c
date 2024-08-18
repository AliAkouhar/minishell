/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:11:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/18 17:57:40 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	size_t	len1;
	char	*newstring;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	newstring = malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstring[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		newstring[len1] = s2[i];
		len1++;
	}
	newstring[len1] = '\0';
	return (newstring);
}

void	pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		path = g_data->pwd;
	printf("%s\n", path);
	if (path != g_data->pwd)
		fre(path);
}
