/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:44:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/18 01:20:10 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	c;

	if (nb < 0)
	{
		if (nb > -10)
		{
			write(1, "-", 1);
			c = (nb * -1) + '0';
		}
		else
		{
			ft_putnbr(nb / 10);
			c = (nb % 10) * -1 + '0';
		}
	}
	else if (nb < 10)
		c = nb + '0';
	else
	{
		ft_putnbr(nb / 10);
		c = (nb % 10) + '0';
	}
	write(1, &c, 1);
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = +2147483647;
	ft_putnbr(n);
	printf("\n");
	printf("\n");
	n = -2147483647;
	ft_putnbr(n);
	printf("\n");
	printf("\n");
	n = 134;
	ft_putnbr(n);
	printf("\n");
	printf("\n");
	n = -2147483648;
	ft_putnbr(n);
	printf("\n");
	printf("\n");
	return (0);
}*/
