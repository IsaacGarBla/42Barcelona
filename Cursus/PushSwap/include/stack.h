/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/04 17:36:37 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	t_stack_node	*last;
	size_t			len;
}	t_stack;

t_stack_node	*stack_node_create(int value);
t_stack			*stack_create(void);
void			stack_destroy(t_stack *stack);
void			stack_add_first(t_stack *stack, t_stack_node *node);
void			stack_add_last(t_stack *stack, t_stack_node *node);
void			stack_swap(t_stack *stack);
void			stack_push(t_stack *stack_src, t_stack *stack_dst);
void			stack_rotate_up(t_stack *stack);
void			stack_rotate_down(t_stack *stack);
float			stack_compute_disorder(t_stack *stack);
int				stack_locate(t_stack *stack, int value);
int				stack_locate_next(t_stack *stack, int value);
bool			stack_add_value_first(t_stack *stack, int value);
bool			stack_add_value_last(t_stack *stack, int value);

#endif /* STACK_H */
