/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:35:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 02:01:14 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_aux.h"

void	ft_check_format(char spc, va_list args, int *len)
{
	if (spc == 'c')
		ft_putchar_pf(va_arg(args, int), 1, len);
	else if (spc == 's')
		ft_putstr_pf(va_arg(args, char *), 1, len);
	else if (spc == 'p')
		ft_putptr_pf(va_arg(args, void *), 1, len);
	else if (spc == 'd')
		ft_putnbr_pf(va_arg(args, int), 1, len);
	else if (spc == 'i')
		ft_putnbr_pf(va_arg(args, int), 1, len);
	else if (spc == 'u')
		ft_putnbr_base_pf(va_arg(args, unsigned int), "0123456789", 1, len);
	else if (spc == 'x')
		ft_putnbr_base_pf(va_arg(args, unsigned int),
			"0123456789abcdef", 1, len);
	else if (spc == 'X')
		ft_putnbr_base_pf(va_arg(args, unsigned int),
			"0123456789ABCDEF", 1, len);
	else if (spc == '%')
		ft_putchar_pf('%', 1, len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0'
			&& ft_strchr("cspdiuxX%", format[i + 1]) != NULL)
		{
			i++;
			ft_check_format(format[i], args, &total_len);
		}
		else
			ft_putchar_pf(format[i], 1, &total_len);
		i++;
	}
	return (total_len);
}
