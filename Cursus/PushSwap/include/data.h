/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/04 19:44:39 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

#include "stack.h"
#include <stdbool.h>

# define	STR_STG_SIMPLE		"--simple"
# define	STR_STG_MEDIUM		"--medium"
# define	STR_STG_COMPLEX		"--complex"
# define	STR_STG_ADAPTIVE	"--adaptive"
# define	STR_BENCHMARK		"--bench"

typedef enum e_strategy
{
	STG_NONE = 0,
	STG_SIMPLE = 1,
	STG_MEDIUM = 2,
	STG_COMPLEX = 3,
	STG_ADAPTIVE = 4
}	t_strategy;

typedef enum e_status
{
	OK = 0,
	NO_STRATEGY = 1,
	NO_BENCHMARK = 2,
	DUPLICATE_NUMBER = 3,
	UNRECOGNIZED_ARGUMENT  = 4,
	DUPLICATE_STRATEGY = 5,
	DUBLICATE_BENCHMARK = 6,
	STACK_EMPTY = 7,
	MEMORY_ERROR = 8
}	t_status;

typedef struct s_data
{
	bool		bench;
	float		disorder;
	t_strategy	strategy;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_data;

#endif /* DATA_H */
