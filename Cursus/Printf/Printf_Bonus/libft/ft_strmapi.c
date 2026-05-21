/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:47:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:40:21 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string.
 *
 * This function applies the function f to each character of the string s,
 * creating a new string with the results.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return A new string with the results of applying f to each character of s.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dst != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			dst[i] = (*f)(i, s[i]);
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
