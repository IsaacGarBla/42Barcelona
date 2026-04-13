/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:17:26 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 00:24:17 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("El factorial de %s es %d.\n", args[1],
		ft_recursive_factorial(atoi(args[1])));
}
*/