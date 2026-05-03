/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/01 10:14:56 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

t_stack_node	*ft_stack_node_create(int value)
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

t_stack	*ft_stack_create(void)
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

void	ft_stack_destroy(t_stack *stack)
{
	t_stack_node	*node;

	while (stack->len > 0)
	{
		node = stack->first;
		stack->first = stack->first->next;
		free(node);
		stack->len--;
	}
	free(stack);
}

void	ft_stack_add_first(t_stack *stack, t_stack_node *node)
{
	node->next = stack->first;
	node->prev = NULL;
	stack->first = node;
	stack->len++;
	if (node->next != NULL)
		node->next->prev = node;
	else
		stack->last = node;
	return ;
}

void	ft_stack_add_last(t_stack *stack, t_stack_node *node)
{
	node->next = NULL;
	node->prev = stack->last;
	stack->last = node;
	stack->len++;
	if (node->prev != NULL)
		node->prev->next = node;
	else
		stack->first = node;
	return ;
}
