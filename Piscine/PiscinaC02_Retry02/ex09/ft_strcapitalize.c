/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:46:00 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 01:21:29 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_char_to_upcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c = 'A' + c - 'a';
	return (c);
}

char	ft_char_to_lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
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

int	ft_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (ft_char_is_uppercase(str[pos]))
			str[pos] = ft_char_to_lowcase(str[pos]);
		if (pos == 0 || !ft_char_is_alpha(str[pos - 1]))
			str[pos] = ft_char_to_upcase(str[pos]);
		pos++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "#F1!M*)Kem0J4Fn?Wa~Ffnf@NvJi7Tb<% T3N,D_T!$";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strcapitalize(str));
	return (0);
}*/
