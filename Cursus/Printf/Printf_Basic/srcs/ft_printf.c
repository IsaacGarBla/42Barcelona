/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:35:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 02:01:14 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_aux.h"

unsigned int	ft_check_format(char spc, va_list args)
{
	if (spc == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (spc == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (spc == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	else if (spc == 'd')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (spc == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (spc == 'u')
		return (ft_putnbr_base_pf(va_arg(args, unsigned int), "0123456789"));
	else if (spc == 'x')
		return (ft_putnbr_base_pf(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (spc == 'X')
		return (ft_putnbr_base_pf(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (spc == '%')
		return (ft_putchar_pf('%'));
	return (0);
}

char	*ft_find_char(const char *src, const char *set)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (ft_strchr(set, src[i]) != NULL)
			return ((char *) &src[i]);
		i++;
	}
	return (NULL);
}

int	ft_process_flags(int n)
{
	return (n == 1);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;
	unsigned int	total_len;
	char			*p;

	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			p = ft_find_char(&format[i + 1], "cspdiuxX%");
			if (p != NULL)
			{
				/*if (p != &format[i + 1])
					ft_process_flags(1);
				i = i + (int)(p - &format[i]);*/
				total_len += ft_check_format(format[i], args);
			}
			else
				total_len += ft_putchar_pf(format[i]);
		}
		else
			total_len += ft_putchar_pf(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
