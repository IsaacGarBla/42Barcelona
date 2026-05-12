/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:14:35 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:40:00 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a string with a maximum length.
 *
 * This function copies the string src to the string dst, ensuring that
 * the result is null-terminated and does not exceed the specified size.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param siz The maximum length of the destination string.
 * @return The length of the source string.
 */
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
