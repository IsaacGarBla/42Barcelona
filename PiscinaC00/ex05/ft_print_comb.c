/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:06:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 13:06:56 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_number(char number_1, char number_2, char number_3)
{
	write(1, &number_1, 1);
	write(1, &number_2, 1);
	write(1, &number_3, 1);
}

void	ft_print_comb(void)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i <= 7)
	{
		x = i + 1;
		while (x <= 8)
		{
			y = x + 1;
			while (y <= 9)
			{
				write_number(i + '0', x + '0', y + '0');
				if (!(i == 7 && x == 8 && y == 9))
					write(1, ", ", 2);
				y++;
			}
			x++;
		}
		i++;
	}
}

/* Program test

int	main(void)
{
	ft_print_comb();
}
*/
