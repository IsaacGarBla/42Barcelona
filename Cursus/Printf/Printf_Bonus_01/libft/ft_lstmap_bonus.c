/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:58:03 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:44:46 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief	Applies a function to each element of a linked list and creates 
 * 		  	a new list.
 *
 * This function iterates over the linked list pointed to by lst, applies the
 * function f to the content of each element, and creates a new linked list
 * resulting from the successive applications of f. The del function is used 
 * to delete the content of an element if needed.
 *
 * @param lst 	Pointer to the first element of the linked list.
 * @param f 	Pointer to the function to apply to each element's content.
 * @param del 	Pointer to the function used to delete the content of an element
 * 				if needed.
 * @return 		Pointer to the new linked list, or NULL if memory allocation 
 * 				fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*dst;

	dst = NULL;
	while (lst != NULL)
	{
		elem = malloc(sizeof(t_list));
		if (elem != NULL)
		{
			elem->content = (*f)(lst->content);
			elem->next = NULL;
			ft_lstadd_back(&dst, elem);
		}
		else
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (dst);
}
