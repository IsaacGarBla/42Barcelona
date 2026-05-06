/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 01:34:54 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->len > 1)
	{
		tmp = stack->first;
		stack->first = tmp->next;
		stack->first->prev = NULL;
		tmp->next = stack->first->next;
		tmp->prev = stack->first;
		stack->first->next = tmp;
	}
	if (stack->len == 2)
		stack->last = stack->first->next;
}

void	stack_rotate_up(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->first;
	stack->first = stack->first->next;
	stack->first->prev = NULL;
	stack->last->next = tmp;
	tmp->prev = stack->last;
	stack->last = tmp;
	stack->last->next = NULL;
}

void	stack_rotate_down(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	tmp->next = stack->first;
	stack->first = tmp;
	stack->first->prev = NULL;
	stack->first->next->prev = stack->first;
}

float	stack_compute_disorder(t_stack *stack)
{
	long			mistakes;
	long			total_pairs;
	t_stack_node	*node1;
	t_stack_node	*node2;

	mistakes = 0;
	total_pairs = 0;
	if (stack->len < 2)
		return (0);
	node1 = stack->first;
	while (node1 != NULL)
	{
		node2 = node1->next;
		while (node2 != NULL)
		{
			total_pairs++;
			if (node1->value > node2->value)
				mistakes += 1;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (mistakes / total_pairs);
}
