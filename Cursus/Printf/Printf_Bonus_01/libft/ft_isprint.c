/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:27:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:21:51 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is a printable character.
 *
 * This function checks if the character c is a printable character (32-126).
 *
 * @param c The character to check.
 * @return Non-zero if the character is a printable character, zero otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
