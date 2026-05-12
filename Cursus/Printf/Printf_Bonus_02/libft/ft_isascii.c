/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:12:06 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:21:14 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is an ASCII character.
 *
 * This function checks if the character c is a valid ASCII character (0-127).
 *
 * @param c The character to check.
 * @return Non-zero if the character is an ASCII character, zero otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
