/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:59:11 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:58:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Extracts a substring from a string.
 *
 * This function extracts a substring from the string s, starting at the index
 * start and containing at most len characters.
 *
 * @param s		The string to extract the substring from.
 * @param start	The index of the first character to include in the substring.
 * @param len	The maximum number of characters to include in the substring.
 * @return 		A new string containing the extracted substring, or NULL if an
 * 				error occurred.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dst = malloc((len * sizeof(char)) + 1);
	if (dst != NULL)
		ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
