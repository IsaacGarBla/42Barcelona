/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:02:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:02:07 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* #include <stdio.h>

int	main(void)
{
	int	a, b;

	a = 1;
	b = 2;
	printf("El valor de a y b antes del SWAP es: a=%d b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("El valor de a y b despues del SWAP es: a=%d b=%d\n", a, b);
}
*/
