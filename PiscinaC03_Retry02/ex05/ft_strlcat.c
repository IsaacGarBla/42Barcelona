/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 14:54:59 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l_dest;
	unsigned int	l_src;
	unsigned int	i;
	unsigned int	res;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	if (size > l_dest)
		res = l_src + l_dest;
	else
		res = l_src + size;
	i = 0;
	while (src[i] && (l_dest + i + 1) < size)
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (res);
}

/*#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	char			buffer1[200];
	unsigned int	tam = 2;

	ft_strcpy(buffer1, argv[2]);
	printf("Cadena a incluir: %s de longitud %d\n", argv[1],
		ft_strlen(argv[1]));
	printf("Cadena donde incluir %s de longitud %d\n",
		buffer1, ft_strlen(buffer1));
	printf("Size: %d.\n", tam);
	argc = ft_strlcat(buffer1, argv[1], tam);
	printf("Cadena resultado '%s' de tamano %d. => Valor devuelto: %d\n",
		buffer1, ft_strlen(buffer1), argc);
	return (0);
}*/
