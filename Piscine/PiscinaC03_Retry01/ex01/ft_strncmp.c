/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:47:18 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 12:47:21 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while ( x < n && s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x] )
		x++;
	if (x == n && n != 0)
		x--;
	return (s1[x] - s2[x]);
}

/*#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	argc += 0; 
	printf("Cadena S1: %s\n", argv[1]);
	printf("Cadena S2: %s\n", argv[2]);
	printf("Caracteres a comparar: %s\n", argv[3]);
	printf("%d\n", ft_strncmp(argv[1], argv[2], argv[3][0] - '0'));
	printf("%d\n", strncmp(argv[1], argv[2], argv[3][0] - '0'));	
	return (0);
}*/
