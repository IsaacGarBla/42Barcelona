/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:57:33 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 01:57:40 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_safe(int **grid, int dim, int *pos, int num);
int	check_visibility(int **grid, int dim, int *pos, int *input);

void	next_pos(int *current, int *next, int dim)
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
}

int	solve_grid(int **grid, int dim, int *pos, int *input)
{
	int	num;
	int	current[2];
	int	next[2];

	current[0] = pos[0];
	current[1] = pos[1];
	if (current[0] > dim)
		return (1);
	num = 1;
	while (num <= dim)
	{
		if (is_safe(grid, dim, current, num))
		{
			grid[current[0] - 1][current[1] - 1] = num;
			if (check_visibility(grid, dim, current, input))
			{
				next_pos(current, next, dim);
				if (solve_grid(grid, dim, next, input))
					return (1);
			}
			grid[current[0] - 1][current[1] - 1] = 0;
		}
		num++;
	}
	return (0);
}
