/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:57:33 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 23:07:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_safe(int **grid, int dim, int *pos, int num);
int	check_visibility(int **grid, int dim, int *pos, int *input);

int	*next_pos(int *current, int *next, int dim)
{
	if (current[1] == dim)
	{
		next[0] = current[0] + 1;
		next[1] = 1;
	}
	else
	{
		next[0] = current[0];
		next[1] = current[1] + 1;
	}
	return (next);
}

int	solve_grid(int **grid, int dim, int *pos, int *input)
{
	int	num;
	int	next[2];

	if (pos[0] > dim)
		return (1);
	if (grid[pos[0] - 1][pos[1] - 1] != 0)
	{
		return (solve_grid(grid, dim, next_pos(pos, next, dim), input));
	}
	num = 1;
	while (num <= dim)
	{
		if (is_safe(grid, dim, pos, num))
		{
			grid[pos[0] - 1][pos[1] - 1] = num;
			if (check_visibility(grid, dim, pos, input))
			{
				if (solve_grid(grid, dim, next_pos(pos, next, dim), input))
					return (1);
			}
			grid[pos[0] - 1][pos[1] - 1] = 0;
		}
		num++;
	}
	return (0);
}
