/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 01:34:18 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*stack_node_create(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new != NULL)
	{
		new->value = value;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack != NULL)
	{
		stack->len = 0;
		stack->first = NULL;
		stack->last = NULL;
	}
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	t_stack_node	*node;

	if (stack == NULL)
		return ;
	while (stack->len > 0)
	{
		node = stack->first;
		stack->first = stack->first->next;
		free(node);
		stack->len--;
	}
	free(stack);
}

void	stack_push(t_stack *stack, t_stack_node *node)
{
	if (node == NULL)
		return ;
	node->next = stack->first;
	node->prev = NULL;
	if (stack->first != NULL)
		stack->first->prev = node;
	stack->first = node;
	if (stack->last == NULL)
		stack->last = node;
	stack->len++;
	return ;
}

t_stack_node	*stack_pop(t_stack *stack)
{
	t_stack_node	*node;

	if (stack->len == 0)
		return (NULL);
	node = stack->first;
	stack->first = stack->first->next;
	if (stack->first != NULL)
		stack->first->prev = NULL;
	node->next = NULL;
	stack->len--;
	if (stack->len == 0)
		stack->last = NULL;
	return (node);
}
