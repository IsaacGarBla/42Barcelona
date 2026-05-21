/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:15:14 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:59:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Finds the last occurrence of a character in a string.
 *
 * This function searches for the last occurrence of the character c in the
 * string s.
 *
 * @param s	The string to search in.
 * @param c	The character to search for.
 * @return 	A pointer to the last occurrence of c in s, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			last = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (last);
}
