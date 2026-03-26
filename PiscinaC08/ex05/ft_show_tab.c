/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:19:14 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/26 11:19:17 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

void	ft_putnbr(int nbr)
{
	long	nbr_l;
	char	c;

	nbr_l = nbr;
	if (nbr_l >= 10)
		ft_putnbr((int) nbr_l / 10);
	c = '0' + nbr_l % 10;
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	n;

	n = 0;
	while (par[n].str != NULL)
	{
		ft_putstr(par[n].str);
		ft_putstr("\n");
		ft_putnbr(par[n].size);
		ft_putstr("\n");
		ft_putstr(par[n].copy);
		ft_putstr("\n");
		n++;
	}
}
