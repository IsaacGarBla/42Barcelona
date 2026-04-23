/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 03:03:33 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_x.h"

int	ft_printf_x(unsigned long long n, t_flags f, int upper)
{
	int	ln;
	int	lp;

	if (n == 0 && f.dot && f.precision == 0)
		return (0);
	ln = ft_unsigned_nbr_dig(n, 16);
	ln = ln * (f.precision < ln) + f.precision * (f.precision >= ln);
	lp = 2 * (f.hash);
	if (!f.minus && f.zero && !f.dot && f.width > ln + lp)
		ln = ln + (f.width - ln);
	if (!f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (lp)
		ft_putstr_fd("0x", 1);
	if (upper)
		ft_put_unsigned_nbr_base(n, "0123456789ABCDEF", ln);
	else
		ft_put_unsigned_nbr_base(n, "0123456789abcdef", ln);
	if (f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (ln + lp >= f.width)
		return (ln + lp);
	return (f.width);
}
