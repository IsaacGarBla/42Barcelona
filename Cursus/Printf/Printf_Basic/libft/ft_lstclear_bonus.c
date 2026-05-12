/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:44:18 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:24:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears a linked list.
 *
 * This function removes all elements from the linked list pointed to by lst,
 * calling the function del on each element's content.
 *
 * @param lst Pointer to the pointer of the first element of the linked list.
 * @param del Pointer to the function used to delete each element's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	while (*lst != NULL)
	{
		elem = (*lst);
		*lst = (*lst)->next;
		(*del)(elem->content);
		free(elem);
	}
}
