/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:51:55 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:49:56 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory for an array of elements and initializes them to zero.
 *
 * This function allocates memory for an array of nmemb elements, each of size
 * bytes.
 * The allocated memory is initialized to zero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element.
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*p;

	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	if (p != NULL)
		ft_memset(p, 0, total);
	return (p);
}
