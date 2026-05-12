/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:46:26 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:42:10 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * This function sets the first n bytes of the memory area pointed to by s
 * to zero (unsigned char) values.
 *
 * @param s Pointer to the memory area to be set.
 * @param n Number of bytes to be set to zero.
 */

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptr[i++] = '\0';
}
