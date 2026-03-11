/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:54:07 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/10 17:54:10 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = x;
		while (y < size)
		{
			if (tab[x] > tab[y])
				swap(&tab[x], &tab[y]);
			y++;
		}
		x++;
	}
}

/*#include <stdio.h>

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
	int	tab[12] = {25, 1 , 134, 34, 26, 2, 15, 8, 9, 1, 13, 57};

	printf("Array SIN ordenar: ");
	print_array(tab, 12);
	printf("\n");
	ft_sort_int_tab(tab, 12);
	printf("Array ordenado: ");
	print_array(tab, 12);
	printf("\n");
}
*/
