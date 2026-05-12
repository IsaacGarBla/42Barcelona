/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:11:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:55:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Checks if a character is alphanumeric.
 *
 * This function checks if the character c is either a letter (a-z, A-Z) or a
 * digit (0-9).
 *
 * @param c	The character to check.
 * @return	Non-zero if the character is alphanumeric, zero otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
