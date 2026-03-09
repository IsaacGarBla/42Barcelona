/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:15:37 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 11:15:42 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c_letra;

	c_letra = 'z';
	while (c_letra >= 'a')
	{
		write(1, &c_letra, 1);
		c_letra--;
	}
}

/* Program test 

int	main(void)
{
	ft_print_reverse_alphabet();
}
*/
