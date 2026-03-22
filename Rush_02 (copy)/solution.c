/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:56:11 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 20:56:14 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "solution.h"

int	add_space_for_solution(t_solve *sol)
{
	int	i;

	i = 0;
	(*sol).words = malloc (sizeof(char *) * MAX_WORDS);
	while (i < 256)
	{
		(*sol).words[i] = malloc (sizeof(char) * MAX_LONG_WORD);
		i++;
	}
	(*sol).size = 0;
	return (1);
}

int	free_space_for_solution(t_solve *sol)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		free((*sol).words[i]);
		i++;
	}
	free((*sol).words);
	(*sol).size = 0;
	return (1);
}

void	ft_print_sol(t_solve *sol)
{
	int	x;

	x = 0;
	while (x < (*sol).size - 1)
	{
		ft_putstr((*sol).words[x]);
		ft_putstr(" ");
		x++;
	}
	ft_putstr((*sol).words[x]);
	ft_putstr("\n");
}
