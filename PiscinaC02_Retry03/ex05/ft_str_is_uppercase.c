/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:05:14 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 01:30:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (!ft_char_is_uppercase(str[pos]))
			return (0);
		pos++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "HELLO";

	printf("¿Contiene mayúsculas '%s'? -> %d?\n", str, ft_str_is_uppercase(str));
	return (0);
}*/
