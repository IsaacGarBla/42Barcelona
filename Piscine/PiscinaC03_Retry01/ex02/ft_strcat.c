/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:22:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 13:22:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	i;

	x = 0;
	while (dest[x])
		x++;
	i = 0;
	while (src[i])
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
	printf("%s\n", ft_strcat(dest1, argv[2]));
	printf("%s\n",strcat(dest2, argv[2]));
	return (0);
}*/
