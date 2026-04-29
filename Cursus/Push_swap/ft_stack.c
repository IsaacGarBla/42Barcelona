/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/29 11:50:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

t_stack	*ft_stack_create()
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

int	ft_stack_add_first(t_stack *stack, int valor)
{
	t_stack_node	*new;
	new = malloc(sizeof(t_stack_node));
	if (new != NULL)
	{
		new->valor = valor;
		new->next = stack->first;
		new->prev = NULL;
		stack->first = new;
		stack->len++;
		if (new->next != NULL)
			new->next->prev = new;
		else
			stack->last = new;	}
	return (new != NULL);
}

int	ft_stack_add_last(t_stack *stack, int valor);
{
	t_stack_node	*new;
	new = malloc(sizeof(t_stack_node));
	if (new != NULL)
	{
		new->valor = valor;
		new->next = NULL;
		new->prev = stack->last;
		stack->last = new;
		stack->len++;
		if (new->prev != NULL)
			new->prev->next = new;
		else
			stack->first = new;
	}
	return (new != NULL);
}

void	ft_stack_swap(t_stack *stack)
{
	t_stack_node	*tmp;
	
	if (stack->len >1)
	{
		tmp = stack->first;
		stack->first = tmp->next;
		stack-
	}
}
