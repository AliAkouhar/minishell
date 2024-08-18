/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:31:37 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 10:46:21 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	int	i;

	if (!str1 && !str2)
		return (NULL);
	if (str1 == str2)
		return ((void *)str2);
	if (str1 > str2)
	{
		while (len--)
			((unsigned char *)str1)[len] = ((unsigned char *)str2)[len];
	}
	else
	{
		i = 0;
		while ((size_t)i < len)
		{
			((unsigned char *)str1)[i] = ((unsigned char *)str2)[i];
			i++;
		}
	}
	return (str1);
}

/* #include <string.h>
#include <stdio.h>

int	main(void) {
	char str[] = "abcde";
	printf("%s\n", ft_memmove(str + 2 , str, 3));
	printf("%s\n", memmove(str + 2, str, 3));
} */