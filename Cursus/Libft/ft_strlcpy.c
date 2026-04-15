/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:14:35 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/15 13:14:37 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	l_src;
	size_t	i;

	l_src = ft_strlen(src);
	if (siz == 0)
		return (l_src);
	i = 0;
	while (src[i] != '\0' && i < siz -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l_src);
}
