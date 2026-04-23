/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:03:58 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/17 01:27:59 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_initarray(size_t size)
{
	size_t	i;
	char	**dst;

	dst = malloc(size * sizeof(char *));
	if (dst != NULL)
	{
		i = 0;
		while (i < size)
			dst[i++] = NULL;
	}
	return (dst);
}

static char	**ft_free_array(char **dst, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size && dst[i] != NULL)
		free(dst[i++]);
	free(dst);
	dst = NULL;
	return (dst);
}

static int	ft_add_words(char **dst, char const *s, char c)
{
	size_t	j;
	size_t	i;
	int		start;

	i = 0;
	start = -1;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && start == -1)
			start = i;
		else if (s[i] == c && start != -1)
		{
			dst[j] = ft_substr(s, (size_t) start, (size_t)(i - start));
			if (dst[j++] == NULL)
				return (0);
			start = -1;
		}
		i++;
	}
	if (start != -1)
		dst[j] = ft_substr(s, (size_t) start, (size_t)(i - start));
	return (start == -1 || dst[j] != NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	n_words;

	n_words = ft_count_words(s, c);
	dst = ft_initarray(n_words + 1);
	if (dst != NULL && n_words > 0)
		if (!ft_add_words(dst, s, c))
			dst = ft_free_array(dst, n_words + 1);
	return (dst);
}
