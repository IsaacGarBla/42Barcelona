/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:51:55 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/16 13:51:57 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
