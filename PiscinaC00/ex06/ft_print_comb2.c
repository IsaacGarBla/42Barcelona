/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:06:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 13:06:56 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_number(int number_1, int number_2)
{
	char	s_numero[5];

	s_numero[0] = ((number_1 / 10) % 10) + '0';
	s_numero[1] = (number_1 % 10) + '0';
	s_numero[2] = ' ';
	s_numero[3] = ((number_2 / 10) % 10) + '0';
	s_numero[4] = (number_2 % 10) + '0';
	write(1, s_numero, 5);
}

void	ft_print_comb2(void)
{
	int		i;
	int		x;

	i = 0;
	while (i <= 98)
	{
		x = i + 1;
		while (x <= 99)
		{
			write_number(i, x);
			if (!(i == 98 && x == 99))
				write(1, ", ", 2);
			x++;
		}
		i++;
	}
}

/* Program test

int	main(void)
{
	ft_print_comb2();
}

*/
