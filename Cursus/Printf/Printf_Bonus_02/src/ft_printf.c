/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:35:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 13:48:41 by igarcia-         ###   ########.fr       */
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
	else if (spc == 'x')
		return (ft_printf_x(va_arg(args, unsigned int), 0));
	else if (spc == 'X')
		return (ft_printf_x(va_arg(args, unsigned int), 1));
	else if (spc == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	loop_pf(char const *format, va_list args)
{
	unsigned int	i;
	unsigned int	total_len;

	i = 0;
	total_len = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0'
			&& ft_strchr("cspdiuxX%", format[i + 1]) != NULL )
			total_len += ft_check_format(format[i++ + 1], args);
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	return (total_len);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	unsigned int	total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	total_len = loop_pf(format, args);
	va_end(args);
	return (total_len);
}
