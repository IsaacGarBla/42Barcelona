/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 23:52:30 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_di.h"

int	ft_printf_di(long n, t_flags f)
{
	int			ln;
	int			lp;
	long long	nbr;

	nbr = (long long) n * (-1 * (n < 0) + 1 * (n >= 0));
	ln = ft_unsigned_nbr_dig(nbr, 10);
	ln = ln * (f.precision < ln) + f.precision * (f.precision >= ln);
	ln = ln * !(n == 0 && f.dot && f.precision == 0);
	lp = (n < 0 || f.plus || f.space) * !(n == 0 && f.dot && f.precision == 0);
	if (!f.minus && f.zero && !f.dot && f.width > ln + lp)
		ln = ln + (f.width - ln - lp);
	if (!f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (lp)
		ft_putnchar('-' * (n < 0) + '+' * (f.plus && n >= 0)
			+ ' ' * (!f.plus && f.space && n >= 0), 1);
	if (!(n == 0 && f.dot && f.precision == 0))
		ft_put_unsigned_nbr_base(nbr, "0123456789", ln);
	if (f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (ln + lp >= f.width)
		return (ln + lp);
	return (f.width);
}
