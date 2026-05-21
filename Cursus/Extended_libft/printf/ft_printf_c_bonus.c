/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:27:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 14:12:36 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_c_bonus.h"

unsigned int	ft_printf_c(char c, t_flags flags)
{
	if (!flags.minus && flags.width > 1)
		ft_putnchar(' ', flags.width - 1, 1);
	write(1, &c, 1);
	if (flags.minus && flags.width > 1)
		ft_putnchar(' ', flags.width - 1, 1);
	return ((flags.width >= 1) * flags.width + (1 > flags.width) * 1);
}
