/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:02:24 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 14:02:27 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;

	if (size != 0)
	{
		x = 0;
		while (src[x] != '\0' && x < (size -1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (ft_strlen(src));
}

/*#include <stdio.h>

int	main(void)
{
	char				src[] = "Cadena de prueba.";
	char				dest[10];
	unsigned int		tam = 1;
	unsigned int		len;
	
	len = ft_strlcpy(dest, src, tam);
	printf("La cadena que de prueba es: '%s', de longitud %d.\n", src, len);
	printf("Los %d caracteres copiados a destino son: '%s'\n", tam-1, dest);
}*/
