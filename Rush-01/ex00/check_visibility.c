/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:28:40 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 01:21:20 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_ud(int **grid, int dim, int col, int *input)
{
	int	i;
	int	max;
	int	count;

	i = 1;
	while (i <= dim)
	{
		if (grid[i - 1][col - 1] == 0)
			return (1);
		i++;
	}
	i = 1;
	max = 0;
	count = 0;
	while (i <= dim)
	{
		if (grid[i - 1][col - 1] > max)
		{
			max = grid[i - 1][col - 1];
			count++;
		}
		i++;
	}
	return (count == input[col - 1]);
}

int	check_du(int **grid, int dim, int col, int *input)
{
	int	i;
	int	max;
	int	count;

	i = dim;
	while (i >= 1)
	{
		if (grid[i - 1][col - 1] == 0)
			return (1);
		i--;
	}
	i = dim;
	max = 0;
	count = 0;
	while (i >= 1)
	{
		if (grid[i - 1][col - 1] > max)
		{
			max = grid[i - 1][col - 1];
			count++;
		}
		i--;
	}
	return (count == input[dim + col - 1]);
}

int	check_lr(int **grid, int dim, int row, int *input)
{
	int	i;
	int	max;
	int	count;

	i = 1;
	while (i <= dim)
	{
		if (grid[row - 1][i - 1] == 0)
			return (1);
		i++;
	}
	i = 1;
	max = 0;
	count = 0;
	while (i <= dim)
	{
		if (grid[row - 1][i - 1] > max)
		{
			max = grid[row - 1][i - 1];
			count++;
		}
		i++;
	}
	return (count == input[2 * dim + row - 1]);
}

int	check_rl(int **grid, int dim, int row, int *input)
{
	int	i;
	int	max;
	int	count;

	i = dim;
	while (i >= 1)
	{
		if (grid[row - 1][i - 1] == 0)
			return (1);
		i--;
	}
	i = dim;
	max = 0;
	count = 0;
	while (i >= 1)
	{
		if (grid[row - 1][i - 1] > max)
		{
			max = grid[row - 1][i - 1];
			count++;
		}
		i--;
	}
	return (count == input[3 * dim + row - 1]);
}

int	check_visibility(int **grid, int dim, int *pos, int *input)
{
	if (!check_ud(grid, dim, pos[1], input)
		|| !check_du(grid, dim, pos[1], input)
		|| !check_lr(grid, dim, pos[0], input)
		|| !check_rl(grid, dim, pos[0], input))
		return (0);
	else
		return (1);
}
