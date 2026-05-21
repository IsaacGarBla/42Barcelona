/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:42:21 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:46:32 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a block of memory.
 *
 * This function scans the initial n bytes of the memory area pointed to by s
 * for the first instance of c. Both c and the bytes of the memory area are
 * interpreted as unsigned char.
 *
 * @param s	Pointer to the block of memory to scan.
 * @param c	The character to locate, passed as an int but interpreted as an
 * 			unsigned char.
 * @param n	The number of bytes to scan in the memory area.
 * @return	A pointer to the first occurrence of c in the memory area, or NULL
 * 			if c is not found within the first n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *) &ptr[i]);
		else
			i++;
	}
	return (NULL);
}
