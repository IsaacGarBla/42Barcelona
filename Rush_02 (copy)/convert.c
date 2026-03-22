/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:17:43 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 19:17:51 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_atoi(char *str)
{
	int	i;
	int	signo;
	int	valor;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	signo = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	valor = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		valor = valor * 10 + str[i] - '0';
		i++;
	}
	return (valor * signo);
}

char	*ft_itoa(int num, char *str)
{
	int	i;
	int	digito;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num > 0)
	{
		digito = num % 10;
		str[i++] = digito + '0';
		num = num / 10;
	}
	str[i] = '\0';
	ft_rev_str(str);
	return (str);
}
