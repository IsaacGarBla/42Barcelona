/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:06 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/17 10:08:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
