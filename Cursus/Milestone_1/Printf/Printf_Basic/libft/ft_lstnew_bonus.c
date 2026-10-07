/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:39:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:58:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Creates a new element for a linked list.
 *
 * This function allocates memory for a new element of a linked list and 
 * initializes its content with the provided content. The next pointer is set
 * to NULL.
 *
 * @param content	The content to be stored in the new element.
 * @return 			A pointer to the newly created element, or NULL if memory
 * 					allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node != NULL)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
