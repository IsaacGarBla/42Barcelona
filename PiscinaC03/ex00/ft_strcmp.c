/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:26:57 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/13 11:27:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int		x;
	int		diff;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
		diff = (unsigned char) s1[x] - (unsigned char) s2[x];
		if (diff != 0)
			return (diff);
		x++;
	}
	if (s1[x] != '\0' && s2[x] == '\0')
		return (1);
	if (s1[x] == '\0' && s2[x] != '\0')
		return (-1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str1 = "String test 1";
	char	*str2 = "String test 2";

	printf("El resultado de comparar '%s' y '%s' es: ", str1, str2);
	printf("%d.", ft_strcmp(str1, str2));
}*/
