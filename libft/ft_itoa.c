/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:12:52 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/15 18:18:30 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_itoa - Allocates and returns a string representing the integer
 * 			received as an argument.
 * @n: The integer to convert.
 *
 * Return: The string representing the integer or NULL.
 */

static int	count_digits(long n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*get_str(char *str, long n, int count, int negative)
{
	if (count == 0)
		*(str + count + negative) = (n % 10) + '0';
	while (count >= 0)
	{
		*(str + count + negative) = (n % 10) + '0';
		n = n / 10;
		if (count == 0)
			break ;
		count--;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	char	*str;
	int		count;
	int		negative;

	count = count_digits(n);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	str = (char *)malloc(sizeof(char) * (count + 1 + negative));
	if (str == NULL)
		return (NULL);
	if (negative)
		*(str + 0) = '-';
	*(str + count + negative) = '\0';
	count--;
	str = get_str(str, n, count, negative);
	return (str);
}
