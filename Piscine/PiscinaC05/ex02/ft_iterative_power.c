/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:25:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 00:33:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power-- >= 1)
	{
		res = res * nb;
	}
	return (res);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("%s elevado a %s es %d.\n", args[1], args[2],
		ft_iterative_power(atoi(args[1]), atoi(args[2])));
}
*/