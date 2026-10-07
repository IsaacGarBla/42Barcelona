/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:31:55 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:28:21 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes an element from a linked list.
 *
 * This function deletes the element lst from the linked list, calling the
 * function del on its content.
 *
 * @param lst Pointer to the element to delete.
 * @param del Pointer to the function used to delete the element's content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
