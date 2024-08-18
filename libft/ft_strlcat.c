/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:06:49 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 11:28:09 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	j = dest_len;
	i = 0;
	if (size == 0 || size <= dest_len)
		return (size + src_len);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[j] = ((char *)src)[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *src = " world";
	char dest[12] = "hello";
	size_t i = ft_strlcat(dest, src, 2);
	printf("%s %lu", dest, i);
	// printf("%lu ", strlcat(dest, src, 2));
	// printf("%s", dest);
} */