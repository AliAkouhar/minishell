/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:06:28 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 12:10:01 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_striteri - Applies the function ’f’ on each character of the string.
 * @s: The string on which to iterate.
 * @f: The function to apply to each character.
 *
 * Return: void.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* #include <stdio.h>

void	print_char_index(unsigned int index, char *character)
{
	printf("Index: %u, Character: %c\n", index, *character);
}
int	main(void)
{
	char test_string[] = "Hello, World!";
	ft_striteri(test_string, print_char_index);
} */