/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:58:54 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/19 16:04:31 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*str;

	str = (char *)s;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (str[length] == (char)c)
			return (str + length);
		if (length == 0)
			break ;
		length--;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	str = ft_strrchr("tiima", 'i');
	printf("%s", str);
	//printf("%s", strrchr("tiima", 'i'));
} */