/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:25:05 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 11:25:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_ok_put_queen(int *grid, int row, int col, int dim)
{
	int	x;
	int	y;

	x = 0;
	while (x < dim)
	{
		if (grid[x] == col && x++ != row)
			return (0);
		x++;
	}
	x = row - 1;
	y = col - 1;
	while (x >= 0 && y >= 0)
		if (grid[x--] == y--)
			return (0);
	x = row - 1;
	y = col + 1;
	while (x >= 0 && y < dim)
		if (grid[x--] == y++)
			return (0);
	return (1);
}

void	ft_print_solution(int *grid, int dim)
{
	int		x;
	char	c;

	x = 0;
	while (x < dim)
	{
		c = '0' + grid[x];
		write(1, &c, 1);
		x++;
	}
	write(1, "\n", 1);
}

void	ft_queens_solve(int *grid, int dim, int row, int *solves)
{
	int	col;

	if (row == dim)
	{
		*solves = *solves + 1;
		ft_print_solution(grid, dim);
		return ;
	}
	col = 0;
	while (col < dim)
	{
		if (is_ok_put_queen(grid, row, col, dim))
		{
			grid[row] = col;
			ft_queens_solve(grid, dim, row + 1, solves);
			grid[row] = -1;
		}
		col++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10];
	int	tmp;
	int	dim;

	dim = 10;
	tmp = 0;
	while (tmp < dim)
		grid[tmp++] = -1;
	tmp = 0;
	ft_queens_solve(grid, dim, 0, &tmp);
	return (tmp);
}

/*#include <stdio.h>

int	main(void)
{
	ft_ten_queens_puzzle();
}*/
