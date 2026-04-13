/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:00:26 by didguill          #+#    #+#             */
/*   Updated: 2026/03/25 14:06:48 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print_map.h"
#include "bsq.h"
#include <unistd.h>

static void	fill_area(t_map *map);

void	print_map(t_map *map)
{
	int	row;
	int	col;

	fill_area(map);
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			write(1, &(map->grid[row][col]), 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

static void	fill_area(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->biggest_square.size)
	{
		j = 0;
		while (j < map->biggest_square.size)
		{
			map->grid[map->biggest_square.y + i]
			[map->biggest_square.x + j] = map->full_char;
			j++;
		}
		i++;
	}
}
