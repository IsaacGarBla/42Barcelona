/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:48 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/16 12:53:50 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*src1;
	const char	*src2;

	i = 0;
	src1 = (const char *) s1;
	src2 = (const char *) s2;
	while (src1[i] == src2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) src1[i] - (unsigned char) src2[i]);
}
