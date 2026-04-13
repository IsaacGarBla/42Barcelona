/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:42:59 by didguill          #+#    #+#             */
/*   Updated: 2026/03/25 01:13:04 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse_map.h"
#include "solve/solve_map.h"
#include "print/print_map.h"
#include "utils/utils.h"
#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	process_fd(int fd);
static void	init_map(t_map *map);
static void	free_map(t_map *map);

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
		process_fd(0);
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0 || process_fd(fd) == ERROR)
			map_error();
		close(fd);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (OK);
}

static int	process_fd(int fd)
{
	t_map	map;

	init_map(&map);
	if (parse_map(fd, &map) == ERROR)
	{
		free_map(&map);
		return (ERROR);
	}
	solve_map(&map);
	print_map(&map);
	free_map(&map);
	return (OK);
}

static void	init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->empty_char = '\0';
	map->obstacle_char = '\0';
	map->full_char = '\0';
	map->grid = NULL;
	map->biggest_square.size = 0;
	map->biggest_square.x = 0;
	map->biggest_square.y = 0;
}

static void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->y)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}
