/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:32:51 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/15 08:09:23 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_split - Allocates and returns an array of strings obtained by
 * 			splitting ’s’ using the character ’c’ as a delimiter.
 * @s: The string to be split.
 * @c: The delimiter character.
 *
 * Return: The array of new strings resulting from the split or NULL.
 */

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		fre(array[i]);
		i++;
	}
	fre(array);
}

static char	*ft_strncpy(char *dest, char const *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	fill_array(char const *s, char **array, char c, int count)
{
	int	len;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] != c && s[i])
			i++;
		array[j] = (char *)malloc(sizeof(char) * (i - len + 1));
		if (!array[j])
			return (0);
		array[j] = ft_strncpy(array[j], &s[len], (i - len));
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		checker;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	array[count] = 0;
	checker = fill_array(s, array, c, count);
	if (checker == 0)
		free_array(array);
	return (array);
}

/* #include <stdio.h>

int	main(void)
{
	char *str = "This is a test string";
	char **words = ft_split(str, ' ');

	if (words == NULL)
		printf("Error: ft_split returned NULL\n");
	for (int i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
	}
} */