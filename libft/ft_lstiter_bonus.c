/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:01:29 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/16 14:52:58 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstiter - Iterates the list ’lst’ and applies the function
 *              ’f’ on the content of each node.
 * @lst: The address of a pointer to a node.
 * @f:  The address of the function used to iterate on the list.
 *
 * Return: void.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* #include <stdio.h>
void	ft_printf(void *content)
{
	printf("%s\n", (char *)content);
}
int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "node1";
	node1->next = node2;

	node2->content = "node2";
	node2->next = node3;

	node3->content = "node3";
	node3->next = NULL;

	printf("The linked list: ");
	ft_lstiter(node1, ft_printf);
} */