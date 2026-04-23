/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 03:02:52 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putptr_pf.h"

unsigned int	ft_putptr_pf(void *ptr, t_flags f)
{
	int					len;
	unsigned long long	address;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long long) ptr;
	len = 2 + ft_unsigned_nbr_dig(address, 16);
	if (f.dot && f.precision >= len)
		len = f.precision;
	if (!f.minus && f.width > len)
		ft_putnchar((' ' * (!f.zero || f.dot)
				+ '0' * f.zero * !f.dot),
			f.width - len - 2 * f.dot * (f.precision != 0));
	ft_putstr_fd("0x", 1);
	ft_put_unsigned_nbr_base_pad(address, "0123456789abcdef",
		len - 2 * (!f.dot || f.precision == 0), '0');
	if (f.minus && f.width > len)
		ft_putnchar(' ', f.width - len
			- 2 * f.dot * (f.precision != 0));
	return ((f.width >= len) * f.width + (len > f.width) * len);
}
