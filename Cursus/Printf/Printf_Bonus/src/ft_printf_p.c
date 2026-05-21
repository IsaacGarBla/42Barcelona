/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:34:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 17:24:39 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

unsigned int	ft_printf_p(void *ptr)
{
	int	ln;

	ln = ft_unsigned_nbr_dig((unsigned long long) ptr, 16);
	if (ptr)
	{
		ft_putstr_fd("0x", 1);
		ft_put_unsigned_nbr_base((unsigned long long) ptr,
			"0123456789abcdef", ln);
		return (ln + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}
