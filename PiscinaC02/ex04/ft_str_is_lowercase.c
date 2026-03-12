/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:52:05 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 00:53:36 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (!ft_char_is_lowercase(str[pos]))
			return (0);
		pos++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "patrAuzeciidoi";

	printf("¿Contiene solo minúsculas la cadena '%s'? -> %d?\n", str, ft_str_is_lowercase(str));
	return (0);
}*/
