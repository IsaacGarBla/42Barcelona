/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:39:31 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 14:39:35 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	y;

	x = 0;
	while (str[x])
	{
		if (str[x] == to_find[0])
		{
			y = 1;
			while (str[x + y] && to_find[y]
				&& str[x + y] == to_find[y])
				y++;
			if (!to_find[y])
				return (&str[x]);
		}
		x++;
	}
	return (NULL);
}

/*#include <string.h>

int main(int argc, char **argv)
{
	
	argc += 0;
	
	printf("Cadena donde buscar: %s\n", argv[1]);
	printf("Cadena a buscar: %s\n", argv[2]);
	printf("%s\n", ft_strstr(argv[1], argv[2]));
	printf("%s\n", strstr(argv[1], argv[2]));
	return (0);
}*/
