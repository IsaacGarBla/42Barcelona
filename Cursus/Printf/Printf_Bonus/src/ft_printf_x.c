/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/07 00:17:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_x.h"

int	ft_printf_x(unsigned long long n, int upper)
{
	int	ln;

	ln = ft_unsigned_nbr_dig(n, 16);
	if (upper)
		ft_put_unsigned_nbr_base(n, "0123456789ABCDEF", ln);
	else
		ft_put_unsigned_nbr_base(n, "0123456789abcdef", ln);
	return (ln);
}
