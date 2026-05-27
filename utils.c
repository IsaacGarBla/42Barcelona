/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:25 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/15 18:38:49 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_data(t_data *data)
{
	if (data->stack_a != NULL)
		stack_destroy(data->stack_a);
	if (data->stack_b != NULL)
		stack_destroy(data->stack_b);
}

bool	is_valid_int(const char *str, int *value)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (false);
		str++;
	}
	*value = (int)num * sign;
	return (true);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	sa(t_data *ps)
{
	stack_swap(ps->stack_a);
	ps->mov.sa++;
	ft_printf("sa\n");
}

void	sb(t_data *ps)
{
	stack_swap(ps->stack_b);
	ps->mov.sb++;
	ft_printf("sb\n");
}

void	ss(t_data *ps)
{
	stack_swap(ps->stack_a);
	stack_swap(ps->stack_b);
	ps->mov.ss++;
	ft_printf("ss\n");
}

void	pa(t_data *ps)
{
	stack_push(ps->stack_a, stack_pop(ps->stack_b));
	ps->mov.pa++;
	ft_printf("pa\n");
}

void	pb(t_data *ps)
{
	stack_push(ps->stack_b, stack_pop(ps->stack_a));
	ps->mov.pb++;
	ft_printf("pb\n");
}

void	ra(t_data *ps)
{
	stack_rotate_up(ps->stack_a);
	ps->mov.ra++;
	ft_printf("ra\n");
}

void	rb(t_data *ps)
{
	stack_rotate_up(ps->stack_b);
	ps->mov.rb++;
	ft_printf("rb\n");
}

void	rr(t_data *ps)
{
	stack_rotate_up(ps->stack_a);
	stack_rotate_up(ps->stack_b);
	ps->mov.rr++;
	ft_printf("rr\n");
}

void	rra(t_data *ps)
{
	stack_rotate_down(ps->stack_a);
	ps->mov.rra++;
	ft_printf("rra\n");
}

void	rrb(t_data *ps)
{
	stack_rotate_down(ps->stack_b);
	ps->mov.rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_data *ps)
{
	stack_rotate_down(ps->stack_a);
	stack_rotate_down(ps->stack_b);
	ps->mov.rrr++;
	ft_printf("rrr\n");
}

static void	print_int_err(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr_fd(num, 2);
	free(num);
}

static void	print_mov_err(t_movements mov)
{
	ft_putstr_fd("[bench] sa: ", 2);
	print_int_err(mov.sa);
	ft_putstr_fd(" sb: ", 2);
	print_int_err(mov.sb);
	ft_putstr_fd(" ss: ", 2);
	print_int_err(mov.ss);
	ft_putstr_fd(" pa: ", 2);
	print_int_err(mov.pa);
	ft_putstr_fd(" pb: ", 2);
	print_int_err(mov.pb);
	ft_putstr_fd("\n[bench] ra: ", 2);
	print_int_err(mov.ra);
	ft_putstr_fd(" rb: ", 2);
	print_int_err(mov.rb);
	ft_putstr_fd(" rr: ", 2);
	print_int_err(mov.rr);
	ft_putstr_fd(" rra: ", 2);
	print_int_err(mov.rra);
	ft_putstr_fd(" rrb: ", 2);
	print_int_err(mov.rrb);
	ft_putstr_fd(" rrr: ", 2);
	print_int_err(mov.rrr);
}

static void	print_float(float n)
{
	char	*num;

	num = ft_itoa((int) n );
	ft_putstr_fd(num, 2);
	ft_putstr_fd(".", 2);
	free(num);
	num = ft_itoa((int) ((n - ((int) n)) * 100));
	ft_putstr_fd(num, 2);
	ft_putstr_fd("%", 2);
	free(num);
}

void	print_stats(t_data *ps)
{
	ft_putstr_fd("[bench] disorder:     ", 2);
	print_float(ps->disorder * 100);
	ft_putstr_fd("\n[bench] strategy:   ", 2);
	if (ps->strategy_selected == STG_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (ps->strategy_selected == STG_MEDIUM)
		ft_putstr_fd("Medium / O(n \u221A n)\n", 2);
	else if (ps->strategy_selected == STG_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptative / ", 2);
		if (ps->strategy_executed == STG_SIMPLE)
			ft_putstr_fd("O(n^2)\n", 2);
		else if (ps->strategy_executed == STG_MEDIUM)
			ft_putstr_fd("O(n \u221A n)\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
	ft_putstr_fd("[bench] total_ops:  ", 2);
	print_int_err(ps->mov.sa + ps->mov.sb + ps->mov.ss + ps->mov.pa
		+ ps->mov.pb + ps->mov.ra + ps->mov.rb + ps->mov.rr
		+ ps->mov.rra + ps->mov.rrb + ps->mov.rrr);
	ft_putstr_fd("\n", 2);
	print_mov_err(ps->mov);
}
/* void	print_stats(t_data *ps)
{
	t_stack_node	*current;

	ft_printf("Stack A Length: %d\n", (int) ps->stack_a->len);
	current = ps->stack_a->first;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
	if (ps->strategy == STG_NONE)
		ft_printf("Strategy: None\n");
	else if (ps->strategy == STG_SIMPLE)
		ft_printf("Strategy: Simple\n");
	else if (ps->strategy == STG_MEDIUM)
		ft_printf("Strategy: Medium\n");
	else if (ps->strategy == STG_COMPLEX)
		ft_printf("Strategy: Complex\n");
	else if (ps->strategy == STG_ADAPTIVE)
		ft_printf("Strategy: Adaptive\n");
	else
		ft_printf("Strategy: Unknown\n");
	if (ps->bench)
		ft_printf("Benchmark: Enabled\n");
	else
		ft_printf("Benchmark: Disabled\n");
	ft_printf("Movements\n");
	ft_printf("=========\n");
	ft_printf("SA %d.\n", ps->mov.sa);
	ft_printf("SB %d.\n", ps->mov.sb);
	ft_printf("SS %d.\n", ps->mov.ss);
	ft_printf("PA %d.\n", ps->mov.pa);
	ft_printf("PB %d.\n", ps->mov.pb);
	ft_printf("RA %d.\n", ps->mov.ra);
	ft_printf("RB %d.\n", ps->mov.rb);
	ft_printf("RR %d.\n", ps->mov.rr);
	ft_printf("RRA %d.\n", ps->mov.rra);
	ft_printf("RRB %d.\n", ps->mov.rrb);
	ft_printf("RRR %d.\n", ps->mov.rrr);
} */
