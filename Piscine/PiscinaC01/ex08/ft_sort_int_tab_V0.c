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

int*	merge(int *tab_a, int size1, int *tab_b, int size2)
{
	int	pos_a;
	int	pos_b;
	int pos_c;

	pos_a = 0;
	pos_b = 0;

	while (pos_a < size1)
	{
		if (tab_a[pos_a] <= tab_b[pos_b])
			pos_a++;
		else
		{
			swap(&tab_a[pos_a], &tab_b[pos_b]);
			pos_c = pos_b;
			while (pos_c < size2 - 1 && tab_b[pos_c] > tab_b[pos_c+1])
			{
				swap(&tab_b[pos_c], &tab_b[pos_c + 1]);
				pos_c++;
			}
		}
	}
	return tab_a;
}

int*	sort_tab(int *tab, int size)
{
	int s_p_1;
	int s_p_2;

	if (size <= 1)
  		return tab;
	else 
	{
		s_p_1 = size / 2;
		if (size %  2 == 0)
			s_p_2 = s_p_1;
		else
			s_p_2 = s_p_1 + 1;
		return merge(sort_tab(tab, s_p_1), s_p_1, sort_tab(&tab[s_p_1], s_p_2), s_p_2);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	sort_tab(tab, size);
}

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
	int	tab[2] = {25};

	printf("Array SIN ordenar: ");
	print_array(tab, 1);
	printf("\n");
	ft_sort_int_tab(tab, 1);
	printf("Array ordenado: ");
	print_array(tab, 1);
	printf("\n");
}