/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:30:16 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 13:30:19 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char 	*tf_lowcase(char *str)
{
	*str = 'a' + *str - 'A';
}

char	*ft_strlowcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
			str[pos] = 'a' + str[pos] - 'A';
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
