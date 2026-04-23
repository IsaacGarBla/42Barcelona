/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:27:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 03:31:35 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar_pf.h"

unsigned int	ft_putchar_pf(char c, t_flags flags)
{
	if (!flags.minus && flags.width > 1)
		ft_putnchar(' ', flags.width - 1);
	ft_putchar_fd(c, 1);
	if (flags.minus && flags.width > 1)
		ft_putnchar(' ', flags.width - 1);
	return ((flags.width >= 1) * flags.width + (1 > flags.width) * 1);
}
