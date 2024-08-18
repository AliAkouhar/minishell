/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:00:06 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/23 09:09:40 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

/* #include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *ptr = ft_calloc(4 , sizeof(INT_MAX));
	int i = 0;
	while (i < 4)
	{
		printf("%i\n", ptr[i]);
		i++;
	}
} */