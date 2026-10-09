/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:49:24 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/13 15:49:27 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*vector;
	int	x;

	if (min >= max)
		return (NULL);
	vector = malloc((max - min) * sizeof(int));
	if (vector != NULL)
	{
		x = 0;
		while (x < max - min)
		{
			vector[x] = min + x;
			x++;
		}
	}
	return (vector);
}

/*#include <stdio.h>

int	main(int nargs, char **args)
{
	int	*vector;
	int	min;
	int	max;
	int	x;

	nargs = nargs + 0;
	min = atoi(args[1]);
	max = atoi(args[2]);
	vector = ft_range(min, max);
	if (vector != NULL)
	{
		x = 0;
		while (x < max - min)
		{
			printf("El numero de la posicion %d es %d.\n", x, vector[x]);
			x++;
		}
	}
}*/
