/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:36:26 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:36:29 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	inici;
	int	fin;
	int	temp;

	inici = 0;
	fin = size - 1;
	while (inici <= size / 2 -1)
	{
		temp = tab[inici];
		tab[inici] = tab[fin];
		tab[fin] = temp;
		inici++;
		fin--;
	}
}

/*
#include <stdio.h>

void	print_array(int *tab, int size)
{
	int	x;

	x = 0;
	while (x < size -1)
	{
		printf("%d, ", tab[x]);
		x++;
	}
	printf("%d", tab[x]);
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};

	printf("Array antes de invertir: ");
	print_array(tab, 5);
	printf("\n");
	ft_rev_int_tab(tab, 5);
	printf("Array despues de invertir: ");
	print_array(tab, 5);
	printf("\n");
}
*/
