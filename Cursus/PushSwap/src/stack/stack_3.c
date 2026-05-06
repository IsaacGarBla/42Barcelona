/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 01:38:24 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

ssize_t	stack_locate(t_stack *stack, int value)
{
	ssize_t			pos;
	t_stack_node	*curr;

	pos = 0;
	curr = stack->first;
	while (curr != NULL)
	{
		if (curr->value == value)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

size_t	stack_locate_min(t_stack *stack)
{
	size_t			curr_pos;
	size_t			pos;
	int				min_value_found;
	t_stack_node	*curr;

	curr_pos = 0;
	pos = 0;
	min_value_found = INT_MAX;
	curr = stack->first;
	while (curr != NULL)
	{
		if (curr->value <= min_value_found)
		{
			pos = curr_pos;
			min_value_found = curr->value;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (pos);
}

size_t	stack_locate_next(t_stack *stack, int value)
{
	size_t			curr_pos;
	size_t			pos;
	int				max_value_found;
	t_stack_node	*curr;

	curr_pos = 0;
	pos = 0;
	max_value_found = INT_MAX;
	curr = stack->first;
	while (curr != NULL)
	{
		if (curr->value > value && curr->value < max_value_found)
		{
			pos = curr_pos;
			max_value_found = curr->value;
		}
		if (max_value_found == value + 1)
			break ;
		curr = curr->next;
		curr_pos++;
	}
	return (pos);
}
