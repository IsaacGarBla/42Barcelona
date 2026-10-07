/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:48 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:50:00 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two blocks of memory.
 *
 * This function compares the first n bytes of the memory areas s1 and s2.
 * It returns an integer less than, equal to, or greater than zero if the
 * first n bytes of s1 are found, respectively, to be less than, to match,
 * or be greater than the first n bytes of s2. The comparison is done using
 * unsigned characters.
 *
 * @param s1	Pointer to the first block of memory.
 * @param s2	Pointer to the second block of memory.
 * @param n		The number of bytes to compare.
 * @return		An integer less than, equal to, or greater than zero if the 
 * 				first n bytes of s1 are found, respectively, to be less than,
 * 				sto match, or be greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*src1;
	const char	*src2;

	i = 0;
	src1 = (const char *) s1;
	src2 = (const char *) s2;
	while (i < n && src1[i] == src2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) src1[i] - (unsigned char) src2[i]);
}
