/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 03:02:52 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

unsigned int	ft_printf_p(void *ptr, t_flags f)
{
	int	ln;
	int	lp;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ln = ft_unsigned_nbr_dig((unsigned long long) ptr, 16);
	ln = ln * (f.precision < ln) + f.precision * (f.precision >= ln);
	lp = 2;
	if (!f.minus && f.zero && !f.dot && f.width > ln + lp)
		ln = ln + (f.width - ln);
	if (!f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (lp)
		ft_putstr_fd("0x", 1);
	ft_put_unsigned_nbr_base((unsigned long long) ptr, "0123456789abcdef", ln);
	if (f.minus && f.width - ln - lp > 0)
		ft_putnchar(' ', f.width - ln - lp);
	if (ln + lp >= f.width)
		return (ln + lp);
	return (f.width);
}
