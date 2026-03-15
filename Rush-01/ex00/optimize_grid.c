/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:26:06 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/15 23:31:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_down_up(int **grid, int input, int pos, int dim)
{
	int	i;

	if (input == 1)
		grid[dim - 1][pos % dim] = dim;
	else
	{
		i = dim - 1;
		while (i >= 0)
		{
			grid[i][pos % dim] = i + 1;
			i--;
		}
	}
}

void	fill_up_down(int **grid, int input, int pos, int dim)
{
	int	i;

	if (input == 1)
		grid[0][pos % dim] = dim;
	else
	{
		i = 0;
		while (i < dim)
		{
			grid[i][pos % dim] = i + 1;
			i++;
		}
	}
}

void	fill_left_right(int **grid, int input, int pos, int dim)
{
	int	i;

	if (input == 1)
		grid[pos % dim][0] = dim;
	else
	{
		i = 0;
		while (i < dim)
		{
			grid[pos % dim][i] = i + 1;
			i++;
		}
	}
}

void	fill_right_left(int **grid, int input, int pos, int dim)
{
	int	i;

	if (input == 1)
		grid[pos % dim][dim - 1] = dim;
	else
	{
		i = dim -1;
		while (i >= dim)
		{
			grid[pos % dim][i] = i + 1;
			i--;
		}
	}
}

void	optimize_grid(int **grid, int dim, int *input)
{
	int	i;

	i = 0;
	while (i < dim * 4)
	{
		if (input[i] == 1 || input[i] == dim)
		{
			if (i < dim)
				fill_up_down(grid, input[i], i, dim);
			else if (i < dim * 2)
				fill_down_up(grid, input[i], i, dim);
			else if (i < dim * 3)
				fill_left_right(grid, input[i], i, dim);
			else
				fill_right_left(grid, input[i], i, dim);
		}
		i++;
	}
}
