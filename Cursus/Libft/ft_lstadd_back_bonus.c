/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:44:30 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/19 23:36:30 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
