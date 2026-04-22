/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 05:17:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr_pf.h"

int	ft_ndigits_signed(long long n, int base)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	n = n / base;
	while (n != 0)
	{
		n = n / base;
		digits++;
	}
	return (digits);
}

int	ft_ndigits_unsigned(unsigned long n, int base)
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

unsigned int	ft_putnbr_pf(int n, t_flags flags)
{
	int	len;

	len = ft_ndigits_signed(n, 10);
	if (!flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	ft_putnbr_fd(n, 1);
	if (flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	return ((flags.width >= len) * flags.width + (len > flags.width) * len);
}

void	ft_putnbr_base(unsigned long long n, char *base)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (n >= b)
		ft_putnbr_base(n / b, base);
	write(1, &base[n % b], 1);
}

unsigned int	ft_putnbr_base_pf(unsigned long long n,
			char *base, t_flags flags)
{
	int	len;

	len = ft_ndigits_unsigned(n, ft_strlen(base));
	if (!flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	ft_putnbr_base(n, base);
	if (flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	return ((flags.width >= len) * flags.width + (len > flags.width) * len);
}
