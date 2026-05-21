/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:39:59 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:28:39 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a specific value.
 *
 * This function fills the first n bytes of the memory area pointed to by s
 * with the constant byte c. The value of c is passed as an int, but the
 * function fills the memory area using the unsigned char conversion of c.
 *
 * @param s Pointer to the block of memory to fill.
 * @param c The value to be set, passed as an int but converted to unsigned char.
 * @param n The number of bytes to be set to the value.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char) c;
	return (ptr);
}
