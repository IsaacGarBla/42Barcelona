/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimmel <aimmel@student.42bcn.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 03:21:11 by aimmel            #+#    #+#             */
/*   Updated: 2026/03/15 03:21:16 by aimmel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_GRID_H
# define FREE_GRID_H

void	free_grid(int **grid, int dim);
void	free_grid_on_error(int **grid, int rows_allocated);

#endif
