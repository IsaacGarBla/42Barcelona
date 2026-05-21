/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:47:54 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/17 10:47:57 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
