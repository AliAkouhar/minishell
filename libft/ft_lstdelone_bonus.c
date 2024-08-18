/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:03 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/15 09:15:06 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * void ft_lstdelone
 *	- Takes as a parameter a node and frees the memory of the node’s content
 * 		using the function ’del’ given as a parameter and free the node.
 * @lst: The node to free.
 * @del: The address of the function used to delete the content.
 *
 * Return: void.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	fre(lst);
}

/* #include <stdio.h>
void	delete(void *s)
{
	free(s);
}

int main ()
{
	char *content;
	content = ft_strdup("Hello, world!");
	t_list *myList = ft_lstnew(content);

	printf("%s\n", (char *)myList->content);
	ft_lstdelone(myList, delete);
	return (0);
} */