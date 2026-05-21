/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:54:30 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/20 14:35:16 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_valid_int(const char *str, int *value)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (false);
		str++;
	}
	*value = (int)num * sign;
	return (true);
}
