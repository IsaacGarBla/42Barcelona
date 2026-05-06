/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 18:17:12 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static bool	add_number(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = stack_node_create(value);
	if (node == NULL)
		return (false);
	else
		stack_push(stack, node);
	return (true);
}

static void	parse_numbers(t_data *ps, char *str)
{
	char		**numbers;
	int			i;
	int			value;

	i = 0;
	numbers = ft_split_full(str, " \t\n\r\f\v");
	while (numbers[i])
	{
		if (!is_valid_int(numbers[i], &value))
			set_error(&ps->error, ERROR_UNRECOGNIZED_ARGUMENT);
		else if (stack_locate(ps->stack_a, value) != -1)
			set_error(&ps->error, ERROR_DUPLICATE_NUMBER);
		else if (!add_number(ps->stack_a, value))
			set_error(&ps->error, ERROR_MEMORY);
		if (has_error(&ps->error))
			break ;
		i++;
	}
	free_split(numbers);
}

static bool	parse_strategy(t_data *ps, char *str)
{
	t_strategy	strategy;

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
			set_error(&ps->error, ERROR_DUPLICATE_STRATEGY);
		else
			ps->strategy = strategy;
	}
	return (strategy != STG_NONE);
}

static bool	parse_benchmark(t_data *ps, char *str)
{
	if (ft_strcmp(str, STR_BENCHMARK) == 0)
	{
		if (ps->bench == true)
			set_error(&ps->error, ERROR_DUPLICATE_BENCHMARK);
		ps->bench = true;
		return (true);
	}
	return (false);
}

void	parse_input(t_data *ps, int argc, char **argv)
{
	bool	arg_parsed;
	int		i;

	i = 1;
	while (i < argc)
	{
		arg_parsed = parse_strategy(ps, argv[i]);
		if (has_error(&ps->error))
			return ;
		if (arg_parsed == false)
		{
			arg_parsed = parse_benchmark(ps, argv[i]);
			if (has_error(&ps->error))
				return;
			if (arg_parsed == false)
			{
				parse_numbers(ps, argv[i]);
				if (has_error(&ps->error))
					return ;
			}
		}
		i++;
	}
	ps->disorder = stack_compute_disorder(ps->stack_a);
	if (ps->stack_a->len == 0)
		set_error(&ps->error, ERROR_STACK_EMPTY);
}
