/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:55:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/17 01:27:53 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
