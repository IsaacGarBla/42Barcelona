/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 14:12:36 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_u_bonus.h"

int	ft_printf_u(unsigned long long n, t_flags f)
{
	int	ln;

	ln = ft_unsigned_nbr_dig(n, 10);
	ln = ln * (f.precision < ln) + f.precision * (f.precision >= ln);
	ln = ln * !(n == 0 && f.dot && f.precision == 0);
	if (!f.minus && f.zero && !f.dot && f.width > ln)
		ln = ln + (f.width - ln);
	if (!f.minus && f.width - ln > 0)
		ft_putnchar(' ', f.width - ln, 1);
	if (!(n == 0 && f.dot && f.precision == 0))
		ft_put_unsigned_nbr_base(n, "0123456789", ln);
	if (f.minus && f.width - ln > 0)
		ft_putnchar(' ', f.width - ln, 1);
	if (ln >= f.width)
		return (ln);
	return (f.width);
}
