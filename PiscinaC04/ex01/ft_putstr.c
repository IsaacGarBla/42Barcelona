/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:41:39 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/16 17:41:47 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

/*int	main(void)
{
	ft_putstr("Cadena a imprimir");
	return (0);
}*/
