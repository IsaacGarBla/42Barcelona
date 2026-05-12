/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:58:56 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:59:41 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Returns the last element of a linked list.
 *
 * This function returns the last element of the linked list pointed to by lst.
 *
 * @param	lst Pointer to the first element of the linked list.
 * @return	Pointer to the last element of the linked list, or NULL if the list
 * 			is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*l;

	l = lst;
	while (l != NULL && l->next != NULL)
		l = l->next;
	return (l);
}
