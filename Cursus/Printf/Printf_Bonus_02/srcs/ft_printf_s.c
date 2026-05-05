/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:32:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/05 16:27:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_s.h"

unsigned int	ft_printf_s(char *s, t_flags flags)
{
	int		len;
	int		i;

	if (s)
		len = ft_strlen(s);
	else
		len = 6 * !(flags.dot && flags.precision < 6);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	if (!flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	if (s)
	{
		i = 0;
		while (i < len)
			write(1, &s[i++], 1);
	}
	else if (!flags.dot || flags.precision >= 6)
		ft_putstr_fd("(null)", 1);
	if (flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	return ((flags.width >= len) * flags.width + (len > flags.width) * len);
}
