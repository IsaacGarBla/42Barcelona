/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:32:01 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 14:32:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	x;
	unsigned int	i;

	x = 0;
	while (dest[x])
		x++;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[x] = src[i];
		x++;
		i++;
	}
	dest[x] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char dest1[255];
	char dest2[255];
	
	argc += 0;
	
	strcpy(dest1,  argv[1]);
	strcpy(dest2,  argv[1]);
	printf("Cadena S1: %s\n", argv[1]);
	printf("Cadena a anadir: %s\n", argv[2]);
	printf("Numero caracteres: %d\n", 20);	
	printf("%s\n", ft_strncat(dest1, argv[2], 20));
	printf("%s\n",strncat(dest2, argv[2], 20));
	return (0);
}*/
