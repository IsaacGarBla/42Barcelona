/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:06:18 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 00:37:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (!ft_char_is_alpha(str[pos]))
			return (0);
		pos++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "patruzecissidoi";

	printf("%d\n", ft_str_is_alpha(str));
	return (0);
}*/