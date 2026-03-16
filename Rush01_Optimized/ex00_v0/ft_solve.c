/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:30:00 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/14 16:30:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_safe(int **grid, int dim, int *pos, int num);
int	check_visibility(int **grid, int dim, int *pos, int *input);
void	print_grid(int **grid, int dim);

int	ft_solve(int **grid, int dim, int *pos, int *input)
{
	int	number;
	int row_col[2];		

	number = 1;
	row_col[0] = pos[0];
	row_col[1] = pos[1];
	while (number <= dim)
	{

		printf("Row %d / Col %d -> Value %d\n", row_col[0], row_col[1], number);
		if (is_safe(grid, dim, row_col, number))
		{
			grid[row_col[0]- 1][row_col[1] - 1] = number;
			if (check_visibility(grid, dim, row_col, input))
			//if (1)
			{
				if (row_col[0] == dim && row_col[1] == dim)
				{	
					printf ("Solution OK\n");
					return (1);
				}
				else
				{
					if (row_col[1] == dim)
					{
						row_col[0]++;
						row_col[1] = 1;
					}
					else
						row_col[1]++;
				}
				if (ft_solve(grid, dim, row_col, input))
					return (1);
			}
			else
	 		 printf("Error check visibilidad\n");
				 
		}
		else
			printf("Error check seguridad\n");
		print_grid(grid, dim);
		number++;
	}
	grid[row_col[0]- 1][row_col[1] - 1] = 0;
	return (0);
}
