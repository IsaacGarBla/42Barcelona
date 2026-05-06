/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:52:02 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:14 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"

void	init_data(t_data *ps)
{
	ps->bench = 0;
	ps->disorder = 0;
	ps->strategy = STG_NONE;
	ps->sa = 0;
	ps->sb = 0;
	ps->ss = 0;
	ps->pa = 0;
	ps->pb = 0;
	ps->ra = 0;
	ps->rb = 0;
	ps->rr = 0;
	ps->rra = 0;
	ps->rrb = 0;
	ps->rrr = 0;
	reset_error(&ps->error);
	ps->stack_a = stack_create();
	if (ps->stack_a == NULL)
	{
		set_error(&ps->error, ERROR_MEMORY);
		return ;
	}
	ps->stack_b = stack_create();
	if (ps->stack_b == NULL)
	{
		stack_destroy(ps->stack_a);
		set_error(&ps->error, ERROR_MEMORY);
	}

}
