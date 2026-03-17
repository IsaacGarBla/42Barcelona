/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:32:57 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 17:32:59 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = "Longitud de esta cadena?";

	printf("La longitud de la cadena '%s' es: %d.'\n", str, ft_strlen(str));
	return (0);
}*/
