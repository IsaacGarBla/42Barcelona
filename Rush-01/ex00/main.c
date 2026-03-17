/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:29:06 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/17 01:42:22 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		solve_grid(int **grid, int dim, int *pos, int *input);
void	optimize_grid(int **grid, int dim, int *input);
void	free_grid_on_error(int **grid, int rows_allocated);
void	free_grid(int **grid, int dim);

int	validate_input(char *str, int dim)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && (str[i] > (char){dim + '0'} || str[i] < '1'))
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
	i = 1;
	while (i <= dim)
	{
		grid[i - 1] = malloc(sizeof(int) * dim);
		if (!grid[i - 1])
		{
			free_grid_on_error(grid, i);
			return (NULL);
		}
		j = 1;
		while (j <= dim)
		{
			grid[i - 1][j - 1] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

void	print_grid(int **grid, int dim)
{
	int		row;
	int		col;
	char	c;

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
	int	pos[2];
	int	dim;
	int	**grid;

	dim = argv[2][0] - '0';
	if (argc != 3 || !validate_input(argv[1], dim))
		return (write(1, "Error: Input not in correct format\n", 35), 1);
	pos[0] = 0;
	pos[1] = 0;
	while (argv[1][pos[0]])
	{
		if (pos[0] % 2 == 0)
			input[pos[1]++] = argv[1][pos[0]] - '0';
		pos[0]++;
	}
	grid = init_grid(dim);
	optimize_grid(grid, dim, input);
	pos[0] = 1;
	pos[1] = 1;
	if (!solve_grid(grid, dim, pos, input))
		return (write(1, "Error: Unsolvable with given input\n", 35), 1);
	print_grid(grid, dim);
	free_grid(grid, dim);
	return (0);
}
