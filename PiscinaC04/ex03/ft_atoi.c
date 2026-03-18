/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:57:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/18 01:32:39 by igarcia-         ###   ########.fr       */
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
#include <stdlib.h>

int	main(int argvs, char **argv)
{
	argvs = 0;

	printf("FT_ATOI: El valor entero de '%s' es: %d.\n", argv[1],
		ft_atoi(argv[1]));
	printf("ATOI: El valor entero de '%s' es: %d.\n", argv[1], atoi(argv[1]));
	return (0);
}
*/