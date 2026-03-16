/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 02:57:53 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 02:59:55 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_grid_on_error(int **grid, int rows_allocated)
{
	while (rows_allocated >= 1)
	{
		free(grid[rows_allocated - 1]);
		rows_allocated--;
	}
	free(grid);
}

void	free_grid(int **grid, int dim)
{
	int	i;

	i = 1;
	while (i <= dim)
	{
		free(grid[i - 1]);
		i++;
	}
	free(grid);
}
