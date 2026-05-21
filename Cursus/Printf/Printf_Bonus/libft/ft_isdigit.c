/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:11:23 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:21:33 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is a digit.
 *
 * This function checks if the character c is a numeric digit (0-9).
 *
 * @param c The character to check.
 * @return Non-zero if the character is a digit, zero otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
