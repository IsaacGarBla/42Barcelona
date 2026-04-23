/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:35:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 02:00:52 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_check_format(char spc, t_flags flags, va_list args)
{
	if (spc == 'c')
		return (ft_printf_c(va_arg(args, int), flags));
	else if (spc == 's')
		return (ft_printf_s(va_arg(args, char *), flags));
	else if (spc == 'd' || spc == 'i' )
		return (ft_printf_di(va_arg(args, int), flags));
	else if (spc == 'u')
		return (ft_printf_u(va_arg(args, unsigned int), flags));
	else if (spc == 'p')
		return (ft_printf_p(va_arg(args, void *), flags));
	else if (spc == 'x' || spc == 'p')
		return (ft_printf_x(va_arg(args, unsigned int), flags, 0));
	else if (spc == 'X')
		return (ft_printf_x(va_arg(args, unsigned int), flags, 1));
	else if (spc == '%')
		return (ft_putnchar('%', 1));
	return (0);
}

t_flags	ft_init_flags(void)
{
	t_flags	f;

	f.minus = 0;
	f.zero = 0;
	f.dot = 0;
	f.width = 0;
	f.precision = 0;
	f.hash = 0;
	f.space = 0;
	f.plus = 0;
	return (f);
}

int	ft_process_flags(const char *format, unsigned int pos, t_flags *flags)
{
	while (format[pos] == '-' || format[pos] == '0' || format[pos] == '+'
		|| format[pos] == '#' || format[pos] == ' ' )
	{
		flags->minus = flags->minus || format[pos] == '-';
		flags->zero = flags->zero || format[pos] == '0';
		flags->hash = flags->hash || format[pos] == '#';
		flags->space = flags->space || format[pos] == ' ';
		flags->plus = flags->plus || format[pos] == '+';
		pos++;
	}
	while (format[pos] >= '0' && format[pos] <= '9')
		flags->width = (flags->width * 10) + (format[pos++] - '0');
	if (format[pos] == '.')
		flags->dot = (format[pos++] == '.');
	while (format[pos] >= '0' && format[pos] <= '9')
		flags->precision = (flags->precision * 10) + (format[pos++] - '0');
	return (pos);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	total_len;
	t_flags			flags;

	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flags = ft_init_flags();
			i = ft_process_flags(format, i + 1, &flags);
			total_len += ft_check_format(format[i], flags, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}
