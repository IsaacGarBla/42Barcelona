/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:35:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 17:27:55 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_c.h"
#include "ft_printf_s.h"
#include "ft_printf_di.h"
#include "ft_printf_u.h"
#include "ft_printf_p.h"
#include "ft_printf_x.h"
#include "ft_printf.h"

unsigned int	ft_check_format(char spc, va_list args)
{
	if (spc == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (spc == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (spc == 'd' || spc == 'i' )
		return (ft_printf_di(va_arg(args, int)));
	else if (spc == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (spc == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	else if (spc == 'x' || spc == 'p')
		return (ft_printf_x(va_arg(args, unsigned int), 0));
	else if (spc == 'X')
		return (ft_printf_x(va_arg(args, unsigned int), 1));
	else if (spc == '%')
		return (ft_putnchar('%', 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	total_len;

	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]) != NULL)
		{
			total_len += ft_check_format(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}
