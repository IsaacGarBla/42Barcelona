/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:10:05 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:10:10 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a, b, div, mod;

	a = 5;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("El valor entero de %d/%d es: %d\n", a, b, div);
	printf("El modulo de %d/%d es: %d\n", a, b, mod);
}
*/
