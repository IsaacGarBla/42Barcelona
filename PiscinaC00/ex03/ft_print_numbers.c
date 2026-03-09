/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:28:05 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 11:28:11 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c_numero;

	c_numero = '0';
	while (c_numero <= '9')
	{
		write(1, &c_numero, 1);
		c_numero++;
	}
}

/* Program test

int	main(void)
{
	ft_print_numbers();
}

*/
