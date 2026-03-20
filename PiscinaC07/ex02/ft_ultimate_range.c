/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:39:08 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/20 11:39:12 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (max - min);
}

/*#include <stdio.h>

int	main(int nargs, char **args)
{
	int	*vector;
	int	min;
	int	max;
	int	x;

	min = atoi(args[1]);
	max = atoi(args[2]);
	nargs = ft_ultimate_range(&vector, min, max);
	if (vector != NULL)
	{
		x = 0;
		while (x < nargs)
		{
			printf("El numero de la posicion %d es %d.\n", x, vector[x]);
			x++;
		}
		printf("El total de elementos es: %d.\n", nargs);
	}
}*/
