/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:58:15 by didguill          #+#    #+#             */
/*   Updated: 2026/03/25 14:04:50 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve/solve_map.h"
#include "bsq.h"

static int	get_max_square_size(t_map *map, int row, int col);
static int	has_obstacle_in_right_column(t_map *map, int row, int col,
				int expansion);
static int	has_obstacle_in_bottom_row(t_map *map, int row, int col,
				int expansion);

void	solve_map(t_map *map)
{
	int		x;
	int		y;
	int		square_size;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (!(map->grid[y][x] == map->obstacle_char))
			{
				square_size = get_max_square_size(map, y, x);
				if (square_size > map->biggest_square.size)
				{
					map->biggest_square.size = square_size;
					map->biggest_square.x = x;
					map->biggest_square.y = y;
				}
			}
			x++;
		}
		y++;
	}
	return ;
}

static int	get_max_square_size(t_map *map, int row, int col)
{
	int	square_size;
	int	max_expansion;
	int	i;

	square_size = 1;
	if (map->x - col < map->y - row)
		max_expansion = map->x - col -1;
	else
		max_expansion = map->y - row -1;
	i = 1;
	while (i <= max_expansion)
	{
		if (has_obstacle_in_right_column(map, row, col, i)
			|| has_obstacle_in_bottom_row(map, row, col, i))
			return (square_size);
		square_size++;
		i++;
	}
	return (square_size);
}

static int	has_obstacle_in_right_column(t_map *map, int row, int col,
				int expansion)
{
	int	i;

	i = row;
	while (i <= row + expansion)
	{
		if (map->grid[i][col + expansion] == map->obstacle_char)
			return (1);
		i++;
	}
	return (0);
}

static int	has_obstacle_in_bottom_row(t_map *map, int row, int col,
				int expansion)
{
	int	i;

	i = col;
	while (i <= col + expansion)
	{
		if (map->grid[row + expansion][i] == map->obstacle_char)
			return (1);
		i++;
	}
	return (0);
}
