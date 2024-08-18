/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:02 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 12:09:10 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dest_size != 0)
	{
		i = 0;
		while (src[i] && i < dest_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *src = "ali";
	char dest[6];
	size_t i = ft_strlcpy(dest, src, 3);
	printf("%lu %s", i, dest);
	//printf("%lu ", strlcpy(dest, src, 3));
	//printf("%s", dest);
} */
