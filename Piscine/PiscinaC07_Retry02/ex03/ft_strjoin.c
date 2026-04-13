/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:34:23 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/23 14:34:25 by igarcia-         ###   ########.fr       */
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

int	ft_strlen_array(char **str, int size)
{
	int	x;
	int	tot;

	x = 0;
	tot = 0;
	while (x < size)
	{
		tot = tot + ft_strlen(str[x]);
		x++;
	}
	return (tot);
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

char	*ft_concat(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;

	i = 1;
	ft_strcpy(strs[0], &dest[0]);
	j = ft_strlen(strs[0]);
	while (i < size)
	{
		ft_strcpy(sep, &dest[j]);
		j = j + ft_strlen(sep);
		ft_strcpy(strs[i], &dest[j]);
		j = j + ft_strlen(strs[i++]);
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;

	if (size == 0)
	{
		dest = malloc(1 * sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc((ft_strlen_array(strs, size)
				+ (size - 1) * ft_strlen(sep) + 1) * sizeof(char));
	if (dest != NULL)
		ft_concat(size, strs, sep, dest);
	return (dest);
}

/*#include <stdio.h>

int	main(int nargv, char **argv)
{
	char	*sep;
	char	*dest;
	char	*arg[3];

	sep = "";
	arg[0] = "";
	arg[1] = "";
	arg[2] = "";
	dest = ft_strjoin(3, arg, sep);
	printf("La contatenacion es: %s.\n", dest);
	free(dest);
	return (0);
}*/
