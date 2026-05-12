/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:55:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:50:49 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Copies n bytes from memory area src to memory area dest, allowing
 * 			for overlapping.
 *
 * This function copies n bytes from the memory area pointed to by src to the
 * memory area pointed to by dest. The memory areas may overlap; the copy is
 * always done in a non-destructive manner. If dest is less than src, the copy
 * is performed from the beginning of the memory areas. If dest is greater than
 * src, the copy is performed from the end of the memory areas.
 *
 * @param dest	Pointer to the destination memory area.
 * @param src	Pointer to the source memory area.
 * @param n		The number of bytes to copy.
 * @return		A pointer to the destination memory area dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	*ptr_d;
	size_t			i;

	ptr_s = (unsigned char *) src;
	ptr_d = (unsigned char *) dest;
	if (ptr_d < ptr_s)
	{
		i = 0;
		while (i < n)
		{
			ptr_d[i] = ptr_s[i];
			i++;
		}
	}
	else if (ptr_d > ptr_s)
	{
		i = n;
		while (i > 0)
		{
			ptr_d[i - 1] = ptr_s[i - 1];
			i--;
		}
	}
	return (ptr_d);
}
