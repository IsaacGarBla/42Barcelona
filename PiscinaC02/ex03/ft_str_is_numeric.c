/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:59:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 00:36:41 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (!ft_char_is_numeric(str[pos]))
			return (0);
		pos++;
	}
	return (1);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "1234567";

	printf("%d\n", ft_str_is_numeric(str));
	return (0);
}*/
