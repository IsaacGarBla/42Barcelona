/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:54:44 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 01:19:39 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_safe(int **grid, int dim, int *pos, int num)
{
	int	i;
	int	row;
	int	col;

	i = 1;
	row = pos[0];
	col = pos[1];
	while (i <= dim)
	{
		if (grid[row - 1][i - 1] == num)
			return (0);
		i++;
	}
	i = 1;
	while (i <= dim)
	{
		if (grid[i - 1][col - 1] == num)
			return (0);
		i++;
	}
	return (1);
}
