/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:35:27 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:40:18 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings with a maximum length.
 *
 * This function appends the string src to the string dst, ensuring that
 * the result is null-terminated and does not exceed the specified size.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param siz The maximum length of the destination string.
 * @return Length of src plus minimum of siz and length of dst.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	l_dst;
	size_t	l_src;	
	size_t	i;

	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	if (siz <= l_dst)
		return (l_src + siz);
	i = 0;
	while (src[i] != '\0' && i + l_dst < siz -1)
	{
		dst[i + l_dst] = src[i];
		i++;
	}
	dst[i + l_dst] = '\0';
	return (l_src + l_dst);
}
