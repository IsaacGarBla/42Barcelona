/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 14:12:36 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_x_bonus.h"

int	ft_printf_x(unsigned long long n, t_flags f, int upper)
{
	int	ln;
	int	lp;

	ln = ft_unsigned_nbr_dig(n, 16);
	ln = ln * (f.precision < ln) + f.precision * (f.precision >= ln);
	ln = ln * !(n == 0 && f.dot && f.precision == 0);
	lp = 2 * (f.hash) * !(n == 0 && f.precision == 0);
	if (!f.minus && f.zero && !f.dot && f.width > ln + lp)
		ln = ln + (f.width - ln);
	if (!f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp, 1);
	if (lp && !upper)
		ft_putstr_fd("0x", 1);
	if (lp && upper)
		ft_putstr_fd("0X", 1);
	if (upper && !(n == 0 && f.dot && f.precision == 0))
		ft_put_unsigned_nbr_base(n, "0123456789ABCDEF", ln);
	if (!upper && !(n == 0 && f.dot && f.precision == 0))
		ft_put_unsigned_nbr_base(n, "0123456789abcdef", ln);
	if (f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp, 1);
	if (ln + lp >= f.width)
		return (ln + lp);
	return (f.width);
}
