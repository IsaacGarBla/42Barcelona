/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:22:49 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 11:22:54 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_alphabet(void)
{
	char	c_letra;

	c_letra = 'a';
	while (c_letra <= 'z')
	{
		write(1, &c_letra, 1);
		c_letra++;
	}
}

/* Program test

int	main(void)
{
	ft_alphabet();
}
*/
