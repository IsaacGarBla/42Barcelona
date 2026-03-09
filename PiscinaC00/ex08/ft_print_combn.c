/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:43:46 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/09 14:43:54 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_digits[10] = "0123456789";
char	g_used[10] = "0000000000";
char	g_num[10];

void	comb(int n, int pos, int *primero)
{
	int		x;

	if (pos == n)
	{
		if (*primero != 1)
		{
			write(1, ",", 1);
		}
		*primero = 0;
		write(1, g_num, n);
		return ;
	}
	x = pos;
	while (x <= 10 - n + pos)
	{
		if (g_used[x] == '0')
		{
			g_num[pos] = g_digits[x];
			g_used[x] = '1';
			comb(n, pos + 1, primero);
			g_used[x] = '0';
		}
		x++;
	}
}

void	ft_print_combn(int n)
{
	int		primero;

	primero = 1;
	comb(n, 0, &primero);
	write(1, "\n", 1);
}

/* Test function

int	main(void)
{
	ft_print_combn(3);
}

*/
