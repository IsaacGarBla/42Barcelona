/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:49:18 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 00:55:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	x = 0;
	while (x * x <= nb)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("La SQR entera del número %s  es %d.\n", args[1],
		ft_sqrt(atoi(args[1])));
}
*/