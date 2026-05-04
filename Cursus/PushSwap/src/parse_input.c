/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/04 19:40:52 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

t_status parse_numbers(t_data *ps, char *str)
{
	char 			**numbers;
	int 			i = 0;
	int 			value;
	t_status		status;

	i = 0;
	status = OK;
	numbers = ft_split_full(str, " ");
	while (numbers[i] && status == OK)
	{
		if (!is_valid_int(numbers[i], &value))
			status = UNRECOGNIZED_ARGUMENT;
		else if (stack_locate(ps->stack_a, value) != -1)
			status = DUPLICATE_NUMBER;
		else if (!stack_add_value_first(ps->stack_a, value))
			status = MEMORY_ERROR;
		i++;
	}
	free_split(numbers);
	return (status);
}
t_status parse_strategy(t_data *ps, char *str)
{
	t_strategy strategy;

	strategy = STG_NONE;
	if (ft_strcmp(str, STR_STG_SIMPLE) == 0)
		strategy = STG_SIMPLE;
	else if (ft_strcmp(str, STR_STG_MEDIUM) == 0)
		strategy = STG_MEDIUM;
	else if (ft_strcmp(str, STR_STG_COMPLEX) == 0)
		strategy = STG_COMPLEX;
	else if (ft_strcmp(str, STR_STG_ADAPTIVE) == 0)
		strategy = STG_ADAPTIVE;
	if (strategy != STG_NONE)
	{
		if (ps->strategy != STG_NONE)
			return (DUPLICATE_STRATEGY);
		ps->strategy = strategy;
		return (OK);
	}
	return (NO_STRATEGY);
}
t_status parse_benchmark(t_data *ps, char *str)
{

	if (ft_strcmp(str, STR_BENCHMARK) == 0)
	{
		if (ps->bench == true)
			return (DUBLICATE_BENCHMARK);
		ps->bench = true;
		return (OK);
	}
	return (NO_BENCHMARK);
}

int	parse_input(t_data *ps, int argc, char **argv)
{
	int			i;
	t_status	status;

	i = 1;
	status = OK;
	while (i < argc && status == OK)
	{
		status = parse_strategy(ps, argv[i]);
		if (status == NO_STRATEGY)
		{
			status = parse_benchmark(ps, argv[i]);
			if (status == NO_BENCHMARK)
				status = parse_numbers(ps, argv[i]);
		}
		if (status != OK)
			return (status);
		i++;
	}
	ps->disorder = stack_compute_disorder(ps->stack_a);
	return (status && ps->stack_a->len > 0) + STACK_EMPTY * (ps->stack_a->len == 0);
}
