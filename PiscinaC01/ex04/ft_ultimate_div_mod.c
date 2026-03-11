/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:16:26 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:16:32 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	resto;

	div = *a / *b;
	resto = *a % *b;
	*a = div;
	*b = resto;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a, b;

	a = 25;
	b = 4;
	printf("El valor de %d/%d y su resto son: ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%d y %d\n", a, b);
}
*/
