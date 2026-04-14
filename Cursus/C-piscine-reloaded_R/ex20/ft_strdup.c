/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:38:05 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/13 15:38:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

void	ft_strcpy(char *src, char *dst)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dst != NULL)
		ft_strcpy(src, dst);
	return (dst);
}

/*#include <stdio.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 1;
	printf("String a copiar:\t '%s'.\n", args[1]);
	printf("String copiado:\t\t '%s'.\n", ft_strdup(args[1]));
}*/
