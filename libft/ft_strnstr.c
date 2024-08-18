/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:48:48 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 12:16:25 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	if (!str && len == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	length = ft_strlen(to_find);
	while (str[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((str + i), to_find, length) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)

{
	char *s2 = "not";
	// char *i1 = strnstr("this is not me", s2, 30);
	// printf("%s\n", i1);
	char *i2 = ft_strnstr("this is not me", s2, 30);
	printf("%s\n", i2);
} */