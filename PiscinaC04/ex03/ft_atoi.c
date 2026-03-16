/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:57:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 17:57:42 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*#include <stdio.h>

int	main(void)
{
	char	*str = "  ---+--+1234ab567";

	printf("El valor entero de '%s' es: %d.\n", str, ft_atoi(str));
	return (0);
}*/
