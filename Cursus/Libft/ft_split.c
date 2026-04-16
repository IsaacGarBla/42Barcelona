/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:03:58 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/16 16:04:00 by igarcia-         ###   ########.fr       */
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
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c )
			count++;
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
		while (i < n_substr + 1)
			dst[i] = NULL;
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

static char *ft_strdup_word(char const *s, size_t start, size_t end)
{	
	char	*dst;
	size_t	len;

	len = end - start + 1;
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (dst != NULL)
		ft_strlcpy(dst, &src[start], len + 1);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t	l_array;
	char	**dst;
	char	*start;
	char	*end;
	size_t	i;

	l_array = ft_count_words(s, c);
	dst = ft_initarray(l_array + 1);
	if (dst == NULL)
		return (NULL);
	start = s;
	while (*start == c)
		start++;
	i = 0;
	while (i < l_array - 1)
	{
		end = ft_strchr(start, int c)
		dst[i] = ft_strdup_word(s,
			(size_t) start - s, (size_t) end - s - 1);
		if (dst[i] == NULL)
		else
		{
			i++;
			start = end + 1;
		}
	}
}
