/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:34:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/16 15:34:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	len = start + 1;
	while (s1[len] != '\0')
		len++;
	end = len - 1;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
