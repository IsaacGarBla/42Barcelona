/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 03:03:33 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr_pf.h"

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

void	ft_put_unsigned_nbr_base(unsigned long long n, char *base)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (n >= b)
		ft_put_unsigned_nbr_base(n / b, base);
	write(1, &base[n % b], 1);
}

void	ft_put_unsigned_nbr_base_pad(unsigned long long n, char *base,
						int ln, char pad)
{
	int				i;

	i = 1;
	while (i++ <= ln - ft_unsigned_nbr_dig(n, ft_strlen(base)))
		write(1, &pad, 1);
	ft_put_unsigned_nbr_base(n, base);
}

int	ft_put_signed_nbr_pf(long n, t_flags f)
{
	int		len;
	long	nl;

	nl = n * (-1 * (n < 0) + 1 * (n >= 0));
	len = ft_unsigned_nbr_dig(nl, 10);
	if (f.dot && f.precision >= len)
		len = f.precision;
	if (n < 0 && f.zero && !f.dot)
		ft_putnchar('-', 1);
	if (f.plus && n >= 0 && f.zero && !f.dot)
		ft_putnchar('+', 1);
	if (!f.minus && f.width > len + 1 * (n < 0 || f.plus))
		ft_putnchar((' ' * (!f.zero || f.dot)
				+ '0' * f.zero * !f.dot),
			f.width - (len + 1 * (n < 0 || f.plus)));
	if (n < 0 && (!f.zero || f.dot))
		ft_putnchar('-', 1);
	if (f.plus && n >= 0 && (!f.zero || f.dot))
		ft_putnchar('+', 1);
	ft_put_unsigned_nbr_base_pad(nl, "0123456789", len, '0');
	if (f.minus && f.width > len + 1 * (n < 0 || f.plus))
		ft_putnchar(' ', f.width - (len + 1 * (n < 0 || f.plus)));
	return ((f.width >= len) * f.width
		+ (len > f.width) * len + 1 * (n < 0 || f.plus));
}

int	ft_put_unsigned_nbr_base_pf(unsigned long long n, char *base, t_flags f)
{
	int		len;

	len = ft_unsigned_nbr_dig(n, ft_strlen(base));
	if (f.dot && f.precision >= len)
		len = f.precision;
	if (!f.minus && f.width > len)
		ft_putnchar((' ' * (!f.zero || f.dot)
				+ '0' * f.zero * !f.dot),
			f.width - len);
	ft_put_unsigned_nbr_base_pad(n, base, len, '0');
	if (f.minus && f.width > len)
		ft_putnchar(' ', f.width - len);
	return ((f.width >= len) * f.width + (len > f.width) * len);
}
