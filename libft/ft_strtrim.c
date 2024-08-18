/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:02:11 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/15 07:06:37 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strtrim - Allocates and returns a copy of ’s1’ with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 * @s1: The string to be trimmed.
 * @set: The reference set of characters to trim.
 *
 * Return: The trimmed string or NULLL.
 */

static size_t	check(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && check(s1[start], set))
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (check(s1[end], set))
		end--;
	str = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start <= end && s1[start])
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
int	main(void)
{
	char *str;
	str = ft_strtrim("", "ggg");
	printf("%p\n", str);
} */