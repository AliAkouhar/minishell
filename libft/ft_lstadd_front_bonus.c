/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:05:37 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/21 20:28:32 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * void ft_lstadd_front - Adds the node ’new’ at the beginning of the list.
 * @lst: The address of a pointer to the first link of a list.
 * @new: The address of a pointer to the node to be added to the list.
 *
 * Return: void.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>
int main ()
{
	t_list *node1, *node2, *node;
	int a , b ,c;
	a = 1;
	b = 2;
	c = 0;
	t_list *tmp;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node = (t_list *)malloc(sizeof(t_list));
	node1->content = &a;
	node1->next = node2;

	node2->content = &b;
	node2->next = NULL;


	node->content = &c;
	node->next = NULL;
	ft_lstadd_front(&node1, node);

	tmp = node1;
	while (tmp)
	{
		printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
} */