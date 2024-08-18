/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:57:13 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/16 10:40:59 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*filename(char *file)
{
	char	*filename;

	filename = ft_strdup("/tmp/.");
	filename = ft_strjoin(filename, file);
	return (filename);
}

char	*generate_filename(char *arr)
{
	int		fd;
	char	buffer[11];
	char	file[12];
	int		i;
	int		j;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (printf("Error fd\n"), NULL);
	if (read(fd, buffer, 11) != 11)
		return (printf("Error in read\n"), NULL);
	j = 0;
	while (j < 11)
	{
		i = (unsigned char)buffer[j] % 16;
		file[j] = arr[i];
		j++;
	}
	file[j] = '\0';
	close(fd);
	return (filename(file));
}
