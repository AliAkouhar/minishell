/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:44:23 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/30 16:49:00 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstlast - Returns the last node of the list
 * @lst: The beginning of the list.
 *
 * Return: Last node of the list.
 */

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* #include <stdio.h>
int	main(void)
{
	char *s = "hello";
	char *t = "hola";
	char *u = "heeeeey";

	t_list *p0 = ft_lstnew((void *)s);
	t_list *p1 = ft_lstnew((void *)t);
	t_list *p2 = ft_lstnew((void *)u);

	p0->next = p1;
	p1->next = p2;
	p2->next = NULL;
	t_list *last = ft_lstlast(p0);
	printf("%s\n", (char *)last->content);
} */