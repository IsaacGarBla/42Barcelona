/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:06 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:42:30 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the digits in an integer.
 *
 * This function counts the number of digits in the integer n, 
 * including the sign if n is negative.
 *
 * @param n The integer to count digits for.
 * @return The number of digits in the integer.
 */
static int	ft_ndigits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	n = n / 10;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

/**
 * @brief Converts an integer to a string.
 *
 * This function converts the integer n to a string representation.
 *
 * @param n The integer to convert.
 * @return A pointer to the resulting string, or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*dst;
	int		n_digits;
	long	ln;

	n_digits = ft_ndigits(n);
	dst = malloc((n_digits + 1) * sizeof(char));
	if (dst != NULL)
	{
		ln = n;
		if (ln < 0)
		{
			ln = ln * -1;
			dst[0] = '-';
		}
		dst[n_digits--] = '\0';
		while (ln >= 10)
		{
			dst[n_digits] = '0' + (ln % 10);
			ln = ln / 10;
			n_digits--;
		}
		dst[n_digits] = '0' + ln;
	}
	return (dst);
}
