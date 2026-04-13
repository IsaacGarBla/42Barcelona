/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:56:44 by didguill          #+#    #+#             */
/*   Updated: 2026/03/24 21:04:12 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse_map.h"
#include "utils/read_file.h"
#include "utils/utils.h"
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

static int	parse_map_file(const char *file, t_map *map);
static int	parse_header(const char *file, t_map *map);
static int	parse_grid(const char *file, t_map *map, int i);
static int	fill_grid(const char *file, t_map *map);

int	parse_map(int fd, t_map *map)
{
	char	*file;

	file = read_file(fd);
	if (!file)
		return (ERROR);
	if (parse_map_file(file, map) == ERROR)
	{
		free(file);
		return (ERROR);
	}
	free(file);
	return (OK);
}

static int	parse_map_file(const char *file, t_map *map)
{
	int	i;

	if (parse_header(file, map) == ERROR)
		return (ERROR);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	i++;
	if (parse_grid(file, map, i) == ERROR)
		return (ERROR);
	if (fill_grid(file, map) == ERROR)
	{
		i = 0;
		while (i < map->y)
			free(map->grid[i++]);
		free(map->grid);
		return (ERROR);
	}
	return (OK);
}

static int	parse_header(const char *file, t_map *map)
{
	int	i;

	i = 0;
	if (!(file[i] >= '0' && file[i] <= '9'))
		return (ERROR);
	while (file[i] >= '0' && file[i] <= '9')
		map->y = map->y * 10 + (file[i++] - '0');
	if (map->y <= 0)
		return (ERROR);
	if (!file[i] || !file[i + 1] || !file[i + 2] || file[i + 3] != '\n')
		return (ERROR);
	map->empty_char = file[i++];
	map->obstacle_char = file[i++];
	map->full_char = file[i++];
	if (map->empty_char < 32 || map->empty_char > 126
		|| map->obstacle_char < 32 || map->obstacle_char > 126
		|| map->full_char < 32 || map->full_char > 126)
		return (ERROR);
	if (map->empty_char == map->obstacle_char
		|| map->empty_char == map->full_char
		|| map->obstacle_char == map->full_char)
		return (ERROR);
	if (file[i] != '\n')
		return (ERROR);
	return (OK);
}

static int	parse_grid(const char *file, t_map *map, int i)
{
	int	j;
	int	rows;

	rows = 0;
	while (file[i])
	{
		j = 0;
		while (file[i] && file[i] != '\n')
		{
			if (file[i] != map->empty_char && file[i] != map->obstacle_char)
				return (ERROR);
			j++;
			i++;
		}
		if (rows == 0)
			map->x = j;
		else if (j != map->x)
			return (ERROR);
		rows++;
		if (file[i])
			i++;
	}
	if (rows != map->y)
		return (ERROR);
	return (OK);
}

static int	fill_grid(const char *file, t_map *map)
{
	int	i;
	int	j;

	map->grid = (char **)malloc(map->y * sizeof(char *));
	if (!map->grid)
		return (ERROR);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	i++;
	j = 0;
	while (j < map->y)
	{
		map->grid[j] = (char *)malloc((map->x + 1) * sizeof(char));
		if (!map->grid[j])
			return (ERROR);
		ft_strncpy(map->grid[j], &file[i], map->x);
		map->grid[j][map->x] = '\0';
		while (file[i] && file[i] != '\n')
			i++;
		if (file[i] == '\n')
			i++;
		j++;
	}
	return (OK);
}
