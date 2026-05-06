/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 09:41:44 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

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

t_stack			*stack_create(void);
t_stack_node	*stack_node_create(int value);
void			stack_destroy(t_stack *stack);
void			stack_push(t_stack *stack, t_stack_node *node);
t_stack_node	*stack_pop(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_rotate_up(t_stack *stack);
void			stack_rotate_down(t_stack *stack);
float			stack_compute_disorder(t_stack *stack);
ssize_t			stack_locate(t_stack *stack, int value);
size_t			stack_locate_next(t_stack *stack, int value);
size_t			stack_locate_min(t_stack *stack);

#endif /* STACK_H */
