/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/03 23:49:11 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_stack.h"

# define	STG_SIMPLE		1
# define	STG_MEDIUM		2
# define	STG_COMPLEX		3
# define	STG_ADAPTATIVE	4

# define	STR_STG_SIMPLE		"--simple"
# define	STR_STG_MEDIUM		"--medium"
# define	STR_STG_COMPLEX		"--complex"
# define	STR_STG_ADAPTATIVE	"--adaptative"
# define	STR_BENCHMARK		"--bench"


typedef struct s_push_swap
{
	int		bench;
	int		strategy;
	t_stack	*stack;
}	t_push_swap;

#endif 
