/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:30:16 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 01:15:34 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_char_to_lowcase(char c)
{
	c = 'a' + c - 'A';
	return (c);
}

int	ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (ft_char_is_uppercase(str[pos]))
			str[pos] = ft_char_to_lowcase(str[pos]);
		pos++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "PASAR A MINUSCULAS";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strlowcase(str));
	return (0);
}*/
