/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:32:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 13:48:39 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_s.h"

unsigned int	ft_printf_s(char *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}
