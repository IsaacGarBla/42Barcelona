/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:58:03 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/19 23:17:09 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
