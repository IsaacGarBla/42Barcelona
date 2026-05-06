/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:50:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:13 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "stack.h"
# include <stdbool.h>
# include "error.h"

# define STR_STG_SIMPLE		"--simple"
# define STR_STG_MEDIUM		"--medium"
# define STR_STG_COMPLEX	"--complex"
# define STR_STG_ADAPTIVE	"--adaptive"
# define STR_BENCHMARK		"--bench"

typedef enum e_strategy
{
	STG_NONE = 0,
	STG_SIMPLE = 1,
	STG_MEDIUM = 2,
	STG_COMPLEX = 3,
	STG_ADAPTIVE = 4
}	t_strategy;

typedef struct s_data
{
	bool		bench;
	float		disorder;
	t_strategy	strategy;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_error		error;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_data;

#endif /* DATA_H */
