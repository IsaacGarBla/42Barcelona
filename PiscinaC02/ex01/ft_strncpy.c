/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:50:36 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 11:50:42 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	position;

	position = 0;
	while (position < n && src[position] != '\0' )
	{
		dest[position] = src[position];
		position++;
	}
	while (position < n)
	{
		dest[position] = '\0';
		position++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{

	char source[] = "Probando funcion ft_strncpy";
	char test[] = "######################";
	char target[255];
	unsigned int	n;

	test[1] = '%';
	n = 10;
	printf("El string original es: '%s'\n.", source);
	printf("Los %d primeros son: '%s'.\n", n, ft_strncpy(target, source, 10));
}*/
