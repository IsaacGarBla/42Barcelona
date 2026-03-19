/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:07:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 21:08:06 by igarcia-         ###   ########.fr       */
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

	dst = (char *) malloc(ft_strlen(src) + 1);
	ft_strcpy(src, dst);
	return (dst);
}

/*#include <stdio.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 1;
	printf("String a copiar: '%s'\n\n", args[1]);
	printf("String copiado '%s'\n\n", ft_strdup(args[1]));
}*/
