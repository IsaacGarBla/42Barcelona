/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:13:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:40:07 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string.
 *
 * This function creates a copy of the string src.
 *
 * @param src The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if allocation fails.
 */
char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (dst != NULL)
		ft_strlcpy(dst, src, len + 1);
	return (dst);
}
