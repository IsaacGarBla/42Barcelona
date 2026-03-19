/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:43:37 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 00:48:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 2)
		return (index);
	return (ft_fibonacci(index -1) + ft_fibonacci(index -2));
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int nargs, char **args)
{
	nargs = nargs + 0;
	printf("El elemento %s de la serie Fibonacci es %d.\n", args[1],
		ft_fibonacci(atoi(args[1])));
}
*/