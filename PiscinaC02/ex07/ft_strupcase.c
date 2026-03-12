/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:23:51 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 01:14:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char 	ft_char_to_upcase(char c)
{
	c = 'A' + c - 'a';
	return (c);
}

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strupcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (ft_char_is_lowercase(str[pos]))
			str[pos] = ft_char_to_upcase(str[pos]);
		pos++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Pasar a mayusculas.";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strupcase(str));
	return (0);
}*/
