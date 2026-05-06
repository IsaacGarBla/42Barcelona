/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_insertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:04:26 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:15 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	sort_3(t_data *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->stack_a->first->value;
	second = ps->stack_a->first->next->value;
	third = ps->stack_a->last->value;
	if (first > second && second > third)
	{
		ra(ps);
		sa(ps);
	}
	else if (first > second && second < third && first > third)
		ra(ps);
	else if (first > second && second < third && first < third)
		sa(ps);
	else if (first < second && second > third && first > third)
		rra(ps);
	else if (first < second && second > third && first < third)
	{
		sa(ps);
		ra(ps);
	}
}

void	on2_insertion(t_data *ps)
{
	size_t	target_pos;

	if (ps->stack_a->len < 2)
		return ;
	else if (ps->stack_a->len == 2
		&& ps->stack_a->first->value > ps->stack_a->first->next->value)
	{
		sa(ps);
		return ;
	}
	while (ps->stack_a->len > 3)
	{
		target_pos = stack_locate_min(ps->stack_a);
		if (target_pos <= ps->stack_a->len / 2)
			while (target_pos-- > 0)
				ra(ps);
		else
			while (target_pos++ < ps->stack_a->len)
				rra(ps);
		pb(ps);
	}
	sort_3(ps);
	while (ps->stack_b->len > 0)
		pa(ps);
}
