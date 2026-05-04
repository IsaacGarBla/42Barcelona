/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 17:49:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_locate(t_stack *stack, int value)
{
	int				pos;
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

int stack_locate_next(t_stack *stack, int value)
{
	int				curr_pos;
	int				pos;
	int				max_value_found;
	t_stack_node	*curr;

	curr_pos = 0;
	pos = 0;
	max_value_found = __INT_MAX__;
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
bool stack_add_value_first(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = stack_node_create(value);
	if (!node)
		return (false);
	stack_add_first(stack, node);
	return (true);
}

bool stack_add_value_last(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = stack_node_create(value);
	if (!node)
		return (false);
	stack_add_last(stack, node);
	return (true);
}
