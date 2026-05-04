/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/03 23:49:10 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0'
		&& (unsigned char) s1[i] == (unsigned char) s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ps_parse_arg(t_push_swap *ps, int args, char **argv)
{
	int	i;

	if (args < 2)
		return (0);
	i = 1;
	
	if (IsInteger() && ps->stack == NULL)
	{
		return (1);
	}
	else 
	{
		if (ft_strcmp(argv[i], STR_BENCHMARK) == 0 && !ps->bench)
			ps->bench = 1;
		else if (!ps->strategy)
			ps->strategy = STG_SIMPLE * (ft_strcmp(argv[i], STR_STG_SIMPLE) == 0)
					* STG_MEDIUM * (ft_strcmp(argv[i], STR_STG_MEDIUM) == 0)
					* STG_COMPLEX * (ft_strcmp(argv[i], STR_STG_COMPLEX) == 0)
					* STG_ADAPTATIVE * (ft_strcmp(argv[i], STR_STG_ADAPTATIVE) == 0);	
		else
			return (0);
		return (arg + 1);
	}
}

