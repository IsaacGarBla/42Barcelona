/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:43:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:56:27 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Adds a new element to the beginning of a linked list.
 *
 * This function adds the element new to the beginning of the linked list
 * pointed to by lst.
 *
 * @param lst	Pointer to the pointer of the first element of the linked list.
 * @param new	Pointer to the new element to add.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	(*lst) = new;
}
