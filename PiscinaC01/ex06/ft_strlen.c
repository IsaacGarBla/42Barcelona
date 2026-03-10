/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:28:42 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:46 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

/*#include <stdio.h>

int	main(void)
{
	char cadena[] = "Texto de prueba";
	
	printf("La cadena '%s' tiene %d caracteres.", cadena, ft_strlen(cadena));
}*/
