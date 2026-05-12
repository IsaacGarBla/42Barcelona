/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:09:17 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:51:57 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Finds the first occurrence of a substring in a string, up to a 
 * 			specified length.
 *
 * This function searches for the first occurrence of the substring little in
 * the string big, considering at most len characters.
 *
 * @param big 		The string to search in.
 * @param little 	The substring to search for.
 * @param len 		The maximum number of characters to search.
 * @return 			A pointer to the first occurrence of little in big, or
 * 					NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_little;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	l_little = ft_strlen(little);
	while (big[i] != 0 && i < len && len - i >= l_little)
	{
		if (ft_strncmp(&big[i], little, l_little) == 0)
			return ((char *) &big[i]);
		else
			i++;
	}
	return (NULL);
}
