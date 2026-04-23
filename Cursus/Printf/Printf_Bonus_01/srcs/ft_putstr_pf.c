/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:32:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 02:34:06 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putstr_pf.h"

unsigned int	ft_putstr_pf(char *s, t_flags flags)
{
	int		len;
	int		i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	if (!flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	i = 0;
	while (i < len)
		ft_putchar_fd(s[i++], 1);
	if (flags.minus && flags.width > len)
		ft_putnchar(' ', flags.width - len);
	return ((flags.width >= len) * flags.width + (len > flags.width) * len);
}
