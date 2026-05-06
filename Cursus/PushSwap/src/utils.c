/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:25 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:02 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static bool	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	return (count);
}

char	**ft_split_full(char *str, char *charset)
{
	char	**res;
	int		word_count;
	int		i;
	int		j;
	int		start;

	word_count = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_separator(str[i], charset))
			i++;
		if (start < i)
			res[j++] = ft_strndup(str + start, i - start);
	}
	res[j] = NULL;
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0'
		&& (unsigned char) s1[i] == (unsigned char) s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

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

char	*ft_strndup(char *s, int n)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	sa(t_data *ps)
{
	stack_swap(ps->stack_a);
	ps->sa++;
	ft_printf("sa\n");
}

void	sb(t_data *ps)
{
	stack_swap(ps->stack_b);
	ps->sb++;
	ft_printf("sb\n");
}

void	ss(t_data *ps)
{
	sa(ps);
	sb(ps);
	ft_printf("ss\n");
}

void	pa(t_data *ps)
{
	stack_push(ps->stack_a, stack_pop(ps->stack_b));
	ps->pa++;
	ft_printf("pa\n");
}

void	pb(t_data *ps)
{
	stack_push(ps->stack_b, stack_pop(ps->stack_a));
	ps->pb++;
	ft_printf("pb\n");
}

void	ra(t_data *ps)
{
	stack_rotate_up(ps->stack_a);
	ps->ra++;
	ft_printf("ra\n");
}

void	rb(t_data *ps)
{
	stack_rotate_up(ps->stack_b);
	ps->rb++;
	ft_printf("rb\n");
}

void	rr(t_data *ps)
{
	ra(ps);
	rb(ps);
	ft_printf("rr\n");
}

void	rra(t_data *ps)
{
	stack_rotate_down(ps->stack_a);
	ps->rra++;
	ft_printf("rra\n");
}

void	rrb(t_data *ps)
{
	stack_rotate_down(ps->stack_b);
	ps->rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_data *ps)
{
	rra(ps);
	rrb(ps);
	ft_printf("rrr\n");
}

#include <stdio.h> // Remove this line if not needed

void	print_stats(t_data *ps)
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
	ft_printf("SA %d:\n", ps->sa);
	ft_printf("SB %d:\n", ps->sb);
	ft_printf("SS %d:\n", ps->ss);
	ft_printf("PA %d:\n", ps->pa);
	ft_printf("PB %d:\n", ps->pb);
	ft_printf("RA %d:\n", ps->ra);
	ft_printf("RB %d:\n", ps->rb);
	ft_printf("RR %d:\n", ps->rr);
	ft_printf("RRA %d:\n", ps->rra);
	ft_printf("RRB %d:\n", ps->rrb);
	ft_printf("RRR %d:\n", ps->rrr);
}
