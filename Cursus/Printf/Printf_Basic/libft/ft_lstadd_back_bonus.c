/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:44:30 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:51:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Adds a new element to the end of a linked list.
 *
 * This function adds the element new to the end of the linked list pointed to
 * by lst.
 *
 * @param lst	Pointer to the pointer of the first element of the linked list.
 * @param new	Pointer to the new element to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if ((*lst) == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		elem = (*lst);
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = new;
	}
}
