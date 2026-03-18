/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:42:56 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/18 00:30:32 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		x;
	char	*dig_hex;

	dig_hex = "0123456789abcdef";
	x = 0;
	while (str[x] != '\0')
	{
		if (ft_char_is_printable(str[x]))
			write(1, &str[x], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &dig_hex[(unsigned char) str[x] / 16], 1);
			write(1, &dig_hex[(unsigned char) str[x] % 16], 1);
		}
		x++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	ft_putstr_non_printable("Coucou\n\t\btu vas bien?");
	printf("\n");
	ft_putstr_non_printable("Caracteres normales?");
	printf("\n");
	ft_putstr_non_printable("Caracteres más allá del 127.");
	printf("\n");
	ft_putstr_non_printable("¿Los imprime bien?");
	printf("\n");
	ft_putstr_non_printable("\n\t\b Ahora sí parece que está correcto.");
	printf("\n");
	ft_putstr_non_printable("Última prueba.");
	printf("\n");
	return (0);
}
*/