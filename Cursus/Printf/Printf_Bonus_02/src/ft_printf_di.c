/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:09 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_di.h"

int	ft_printf_di(long n)
{
	int			ln;
	long long	nbr;

	nbr = (long long) n * (-1 * (n < 0) + 1 * (n >= 0));
	ln = ft_unsigned_nbr_dig(nbr, 10);
	if (n < 0)
		ft_putnchar('-', 1);
	ft_put_unsigned_nbr_base(nbr, "0123456789", ln);
	return (ln + (n < 0));
}
