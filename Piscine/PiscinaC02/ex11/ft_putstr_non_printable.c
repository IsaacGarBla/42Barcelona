/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:42:56 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/15 01:29:44 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char_hex(char c)
{
	char	*dig_hex;

	dig_hex = "0123456789abcdef";
	write(1, &dig_hex[c / 16], 1);
	write(1, &dig_hex[c % 16], 1);
}

int	ft_char_is_printable(unsigned char c)
{
	if (c <= 31 || c >= 127)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (ft_char_is_printable(str[x]))
			write(1, &str[x], 1);
		else
		{
			write(1, "\\", 1);
			ft_print_char_hex(str[x]);
		}
		x++;
	}
}
