/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:16:51 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:40:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Joins two strings into a new string.
 *
 * This function creates a new string by concatenating the strings s1 and s2.
 *
 * @param s1 The first string to join.
 * @param s2 The second string to join.
 * @return A pointer to the joined string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dst != NULL)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
			dst[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			dst[j++] = s2[i++];
		dst[j] = '\0';
	}
	return (dst);
}
