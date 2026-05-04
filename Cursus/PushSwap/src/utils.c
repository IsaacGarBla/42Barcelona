/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:25 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 19:36:13 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

t_status	error_exit(t_status status)
{
	write(1, "Error\n", 6);
	ft_printf("Error code: %d\n", status);
	exit(status);
}

bool	is_valid_int(const char *str, int *value)
{
	long num = 0;
	int sign = 1;


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
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
			return (false);
		str++;
	}
	*value = (int)num * sign;
	return (true);
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

int	count_words(char *str, char *charset)
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

bool	is_separator(char c, char *charset)
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
void free_split(char **split)
{
	int i = 0;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void print_stacks(t_data *ps)
{
	t_stack_node *curr_a = ps->stack_a->first;
	t_stack_node *curr_b = ps->stack_b->first;

	ft_printf("Strategy %d:\n", ps->strategy);
	ft_printf("Bench %d:\n", ps->bench);
	ft_printf("Stack A: ");
	while (curr_a)
	{
		ft_printf("%d ", curr_a->value);
		curr_a = curr_a->next;
	}
	ft_printf("\nStack B: ");
	while (curr_b)
	{
		ft_printf("%d ", curr_b->value);
		curr_b = curr_b->next;
	}
	ft_printf("\n");
}