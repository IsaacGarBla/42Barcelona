/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/04 18:36:41 by igarcia-         ###   ########.fr       */
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
		tmp->next = stack->first->next;
		tmp->prev = stack->first;
		stack->first->next = tmp;
		stack->first->prev = NULL;
		if (tmp->next != NULL)
			tmp->next->prev = tmp;
		else
			stack->last = tmp;
	}
}

void	stack_push(t_stack *stack_src, t_stack *stack_dst)
{
	t_stack_node	*tmp;

	if (stack_src->len == 0)
		return ;
	tmp = stack_src->first;
	if (stack_src->len > 1)
	{
		stack_src->first = stack_src->first->next;
		stack_src->first->prev = NULL;
	}
	else
	{
		stack_src->first = NULL;
		stack_src->last = NULL;
	}
	stack_src->len--;
	stack_add_first(stack_dst, tmp);
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
	stack->last->next->next = NULL;
	stack->last->next->prev = stack->last;
	stack->last = tmp;
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
