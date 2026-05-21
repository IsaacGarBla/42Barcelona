/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:19:51 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:56:06 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Converts a lowercase letter to uppercase.
 *
 * This function converts the lowercase letter c to uppercase if it is a
 * lowercase letter.
 *
 * @param c	The character to convert.
 * @return	The converted character, or the original character if it is not a
 * 			lowercase letter.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
