/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:01:24 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 11:01:29 by igarcia-         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	x;

	if (nb == 0)
		return (2);
	x = nb + 1;
	while (!ft_is_prime(x))
		x++;
	return (x);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("El número primo después de %s es -> %d\n", args[1],
		ft_find_next_prime(atoi(args[1])));
}
*/
