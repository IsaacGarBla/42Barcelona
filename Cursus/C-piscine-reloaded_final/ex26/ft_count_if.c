/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:21:24 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/14 12:32:25 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

/*int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

#include <stdio.h>

int		main(int args, char **argv)
{
	
	argv[args - 1] = 0;
	printf("El número de argumentos (excepto último) de longitud 1 es: %d.\n",
			ft_count_if(argv, &ft_strlen));
	return (0);
}*/