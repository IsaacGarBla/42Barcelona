/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_aimmel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:29:06 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/14 19:29:31 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_solve(int **grid, int dim, int *pos, int *input);

int	validate_input(char *str, int dim)
{
	int	i;
	int	len;
	char	d;
	
	i = 0;
	len = 0;
	d = dim + '0';
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && (str[i] > d || str[i] < '1'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		len++;
		i++;
	} 
	if (len != 2 * 4 * dim - 1)
		return (0);
	return (1);
}

int	**init_grid(int dim)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(sizeof(int *) * dim);
	if (!grid)
		return (NULL);
	
	i = 0;
	while (i < dim)
	{
		grid[i] = malloc(sizeof(int) * dim);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		j = 0;
		while (j < dim)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

void	print_grid(int **grid, int dim)
{
	char	c;
	int	row;
	int	col;

	row = 1;
	while (row <= dim)
	{
		col = 1;
		while (col <= dim)
		{
			c = grid[row - 1][col - 1] + '0';
			write(1, &c, 1);
			if (col != dim)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

// Input: "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
int	main(int argc, char **argv)
{
	int	input[36];
	int	i;
	int	dim;
	int	pos[2];
	int	**grid;

	dim = 4;
	pos[0] = 1;
	pos[1] = 1;
	if (argc != 2 || !validate_input(argv[1], dim))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
			input[i] = argv[1][i] - '0';
		i++;
	}
	grid = init_grid(dim);
	if (ft_solve(grid, dim, pos, input))
		print_grid(grid, dim);
	return (0);
}
