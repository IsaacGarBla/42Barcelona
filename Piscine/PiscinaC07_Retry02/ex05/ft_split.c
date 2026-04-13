/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:49:28 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/24 13:49:30 by igarcia-         ###   ########.fr       */
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

int	ft_find_word(char *str, char *find, unsigned int ini)
{
	int	x;
	int	y;

	x = ini;
	while (str[x])
	{
		if (str[x] == find[0])
		{
			y = 1;
			while (str[x + y] && find[y]
				&& str[x + y] == find[y])
				y++;
			if (!find[y])
				return (x);
		}
		x++;
	}
	return (-1);
}

int	ft_count_w(char *str, char *sep)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (str[x])
	{
		y = ft_find_word(str, sep, x);
		if (y == -1)
			return (++count);
		if (x != y)
			count++;
		x = y + ft_strlen(sep);
	}
	return (count);
}

char	*ft_add_w(char *str, int ini, int end)
{
	char	*res;
	int		x;

	res = malloc((end - ini + 2) * sizeof(char));
	if (res != NULL)
	{
		x = 0;
		while (x < end - ini + 1)
		{
			res[x] = str[ini + x];
			x++;
		}
		res[x] = '\0';
	}
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**lst;
	int		x;
	int		j;
	int		pos;

	lst = (char **) malloc((ft_count_w(str, charset) + 1) * sizeof(char *));
	if (lst == NULL)
		return (NULL);
	x = 0;
	j = 0;
	pos = ft_find_word(str, charset, j);
	if (pos == x)
		j = pos + ft_strlen(charset);
	while (x < ft_count_w(str, charset))
	{
		pos = ft_find_word(str, charset, j);
		if (pos == -1)
			pos = ft_strlen(str);
		lst[x] = ft_add_w(str, j, pos - 1);
		x++;
		j = ft_find_word(str, charset, j) + ft_strlen(charset);
	}
	lst[x] = NULL;
	return (lst);
}

#include <stdio.h>

int	main(int narg, char **argv)
{
	char	**words;

	printf("El numero palabras separadas por %s en %s es -> %d.\n",
		argv[2], argv[1], ft_count_w(argv[1], argv[2]));
	words = ft_split(argv[1], argv[2]);
	narg = 0;
	while (words[narg] != NULL)
	{
		printf("La palabra en la posición %d es <%s>.\n", narg + 1, words[narg]);
		narg++;
	}
}
