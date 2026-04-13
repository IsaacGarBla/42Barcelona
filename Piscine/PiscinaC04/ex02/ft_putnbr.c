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
	int		c;
	long	nbl;

	nbl = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	if (nbl < 10)
		c = nbl + '0';
	else
	{
		ft_putnbr(nbl / 10);
		c = (nbl % 10) + '0';
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
	n = -2147483647;
	ft_putnbr(n);
	printf("\n");
	n = 0;
	ft_putnbr(n);
	printf("\n");
	n = -256;
	ft_putnbr(n);
	printf("\n");
	n = 134;
	ft_putnbr(n);
	printf("\n");
	n = -2147483648;
	ft_putnbr(n);
	printf("\n");
	return (0);
}*/
