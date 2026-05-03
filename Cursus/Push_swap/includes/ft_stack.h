/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/01 10:39:44 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

#include <stddef.h>

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

t_stack_node	*ft_stack_node_create(int value);
t_stack			*ft_stack_create(void);
void			ft_stack_destroy(t_stack *stack);
void			ft_stack_add_first(t_stack *stack, t_stack_node *node);
void			ft_stack_add_last(t_stack *stack, t_stack_node *node);
void			ft_stack_swap(t_stack *stack);
void			ft_stack_push(t_stack *stack_src, t_stack *stack_dst);
void			ft_stack_rotate_up(t_stack *stack);
void			ft_stack_rotate_down(t_stack *stack);
float			ft_stack_compute_disorder(t_stack *stack);

#endif 
