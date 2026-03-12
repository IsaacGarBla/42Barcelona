/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:19:44 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/13 00:54:47 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

int	ft_str_is_printable(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (!ft_char_is_printable(str[pos]))
			return (0);
		pos++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "AVOASFIOUSASDFJASDF";

	printf("Es printable '%s'? -> %d.\n", str, ft_str_is_printable(str));
	return (0);
}*/
