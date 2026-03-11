/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:42:56 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 17:42:59 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_char_hex(int valor)
{
	char	*dig_hex;

	dig_hex = "0123456789abcdef";
	write(1, &dig_hex[valor / 16], 1);
	write(1, &dig_hex[valor % 16], 1);
}

int	ft_chr_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (ft_chr_is_printable(str[x]))
			write(1, &str[x], 1);
		else
		{
			write(1, "\\", 1);
			ft_print_char_hex(str[x]);
		}
		x++;
	}
}

/*int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/
