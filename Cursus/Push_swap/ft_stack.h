/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/29 11:50:31 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct s_stack_node
{
	int				valor;
	t_stack_node	*next;
	t_stack_node	*prev;
	
} t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	t_stack_node	*last;
	size_t			len;
} t_stack;

t_stack	*ft_stack_create();
void	ft_stack_destroy(t_stack *stack);
int		ft_stack_add_first(t_stack *stack, int valor);
int		ft_stack_add_last(t_stack *stack, int valor);
void	ft_stack_swap(t_stack *stack);
void	ft_stack_push(t_stack *stack_src, t_stack *stack_dst);
void	ft_stack_rotate_up(t_stack *stack);
void	ft_stack_rotate_down(t_stack *stack);

	
#endif 
