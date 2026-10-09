/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:06:07 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/13 15:06:09 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

/*#include <stdio.h>

int	main(int narg, char **argv)
{
	narg = narg + 0;
	printf("La cadena '%s' tiene %d caracteres.", argv[1], ft_strlen(argv[1]));
	return (0);
}*/
