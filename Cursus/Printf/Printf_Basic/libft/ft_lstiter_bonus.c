/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:54:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:59:45 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Iterates over a linked list and applies a function to each element's
 * 			content.
 *
 * This function iterates over the linked list pointed to by lst and applies the
 * function f to the content of each element.
 *
 * @param lst	Pointer to the first element of the linked list.
 * @param f		Pointer to the function to apply to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	elem = lst;
	while (elem != NULL)
	{
		(*f)(elem->content);
		elem = elem->next;
	}
}
