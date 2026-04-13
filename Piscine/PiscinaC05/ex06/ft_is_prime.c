/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:58:36 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 01:08:07 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	x;

	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 == 0)
		return (0);
	x = 3;
	while (x * x <= nb)
	{
		if (nb % x == 0)
			return (0);
		x += 2;
	}
	return (1);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("¿El número %s  es primo? -> %d\n", args[1],
		ft_is_prime(atoi(args[1])));
}
*/
