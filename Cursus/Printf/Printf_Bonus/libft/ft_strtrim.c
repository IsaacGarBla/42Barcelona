/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:34:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:45:44 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Removes leading and trailing characters from a string.
 *
 * This function removes any character from the set from the beginning and end
 *  of the string s1.
 *
 * @param s1	The string to trim.
 * @param set	The set of characters to remove.
 * @return		A pointer to the trimmed string, or NULL if memory allocation
 * 		fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	len = start + 1;
	while (s1[len] != '\0')
		len++;
	end = len - 1;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
