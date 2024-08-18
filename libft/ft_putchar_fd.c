/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:21:54 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 10:04:10 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putchar_fd - Outputs the character ’c’ to the given file descriptor.
 * @c: The character to output.
 * @fd: The file descriptor on which to write.
 *
 * Return: void.
 */

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("hello.txt", O_WRONLY | O_CREAT, 0644);
	printf("%d\n", fd);
	ft_putchar_fd('l', 3); //instead of 3 put fd
	write(1, "\n", 1);
}
 */