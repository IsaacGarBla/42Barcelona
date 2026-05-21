/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:03:58 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:54:22 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Count the number of words in the string s, using c as a delimiter.
 *
 * This function counts the number of words in the string s, where each word
 * is separated by the character c.
 *
 * @param s	The string to count words in.
 * @param c	The delimiter character.
 * @return	The number of words in the string.
 */
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

/**
 * @brief	Creates an array of strings of the specified size, initialized to
 * 			NULL.
 * 
 * This function creates an array of strings of the specified size,
 * initialized to NULL.
 *
 * @param size	The size of the array to create.
 * @return		A pointer to the created array, or NULL if allocation fails.
 */
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

/**
 * @brief	Frees an array of strings and its contents.
 *
 * This function frees each string in the array and then frees the array itself.
 *
 * @param dst	The array of strings to free.
 * @param size	The size of the array.
 * @return		NULL.
 */
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

/**
 * @brief	Add words to the array.
 *
 * This function adds words from the string s to the array dst, using c as a
 * delimiter.
 *
 * @param dst	The array to add words to.
 * @param s		The string to extract words from.
 * @param c		The delimiter character.
 * @return		The converted integer value.
 */
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

/**
 * @brief	Split a string into an array of strings using a specified
 * 			delimiter.
 *
 * This function splits the string s into an array of strings, using the
 * character c as a delimiter.
 *
 * @param s	The string to split.
 * @param c	The delimiter character.
 * @return	A pointer to the array of strings, or NULL if allocation
 * 			fails.
 */
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
