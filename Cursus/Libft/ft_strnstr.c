/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:09:17 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/16 13:09:20 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_little;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	l_little = ft_strlen(little);
	while (big[i] != 0 && i < len && len - i >= l_little)
	{
		if (ft_strncmp(&big[i], little, l_little) == 0)
			return ((char *) &big[i]);
		else
			i++;
	}
	return (NULL);
}
