/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_f_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 14:12:36 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printnbr_f_bonus.h"

int	ft_unsigned_nbr_dig(unsigned long long n, int base)
{
	int	digits;

	digits = 1;
	n = n / base;
	while (n != 0)
	{
		n = n / base;
		digits++;
	}
	return (digits);
}

static void	ft_put_unsigned_nbr_base_aux(unsigned long long n, char *base)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (n >= b)
		ft_put_unsigned_nbr_base_aux(n / b, base);
	write(1, &base[n % b], 1);
}

void	ft_put_unsigned_nbr_base(unsigned long long n, char *base, int len)
{
	unsigned int	b;
	int				i;

	b = ft_strlen(base);
	i = 0;
	while (i++ < len - ft_unsigned_nbr_dig(n, b))
		write(1, "0", 1);
	ft_put_unsigned_nbr_base_aux(n, base);
}
