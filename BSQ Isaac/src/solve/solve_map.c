/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:58:15 by didguill          #+#    #+#             */
/*   Updated: 2026/03/25 01:53:12 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve/solve_map.h"
#include "bsq.h"

int	there_is_obscol(t_map *map, int row, int col, int desp)
{
	int	i;

	i = row;
	while (i <= row + desp)
	{
		if ((*map).grid[i][col + desp] == (*map).obstacle_char)
			return (1);
		else
			i++;
	}
	return (0);
}

int	there_is_obsrow(t_map *map, int row, int col, int desp)
{
	int	i;

	i = col;
	while (i <= col + desp)
	{
		if ((*map).grid[row + desp][i] == (*map).obstacle_char)
			return (1);
		else
			i++;
	}
	return (0);
}

int	max_size(t_map *map, int row, int col)
{
	int	size;
	int	max_desp;
	int	i;

	size = 1;
	if ((*map).x - col < (*map).y - row)
		max_desp = (*map).x - col -2;
	else
		max_desp = (*map).y - row -2;
	i = 1;
	while (i <= max_desp)
	{
		if (there_is_obscol(map, row, col, i)
			|| there_is_obsrow(map, row, col, i))
			return (size);
		size++;
		i++;
	}
	return (size);
}

// Implement the algorithm to find the biggest square in the map
// This could be a dynamic programming approach or any other efficient method
void	solve_map(t_map *map)
{
	int		x;
	int		y;
	int		size;

	y = 0;
	while (y < (*map).y)
	{
		x = 0;
		while (x < (*map).x)
		{
			if (!((*map).grid[y][x] == (*map).obstacle_char))
			{
				size = max_size(map, y, x);
				if (size > (*map).biggest_square.size)
				{
					(*map).biggest_square.size = size;
					(*map).biggest_square.x = x;
					(*map).biggest_square.y = y;
				}
			}
			x++;
		}
		y++;
	}
	return ;
}
