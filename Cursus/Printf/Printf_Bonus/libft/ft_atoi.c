/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:40:12 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:20:37 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * This function converts the initial portion of the string nptr
 * to an integer. It handles optional whitespace, an optional sign,
 * and numeric characters.
 *
 * @param nptr Input string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	signo;
	int	valor;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	signo = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signo *= -1;
		i++;
	}
	valor = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		valor = valor * 10 + nptr[i] - '0';
		i++;
	}
	return (valor * signo);
}
