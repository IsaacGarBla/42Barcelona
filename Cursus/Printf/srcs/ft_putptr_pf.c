/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 05:16:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putptr_pf.h"

unsigned int	ft_putptr_pf(void *ptr, t_flags flags)
{
	int					len;
	unsigned long long	address;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long long) ptr;
	len = 2 + ft_ndigits_unsigned(address, 16);
	if (!flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_pf(address, "0123456789abcdef", flags);
	if (flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	return ((flags.width >= len) * flags.width + (len > flags.width) * len);
}
