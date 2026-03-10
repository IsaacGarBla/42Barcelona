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

int*	sort(int *tab, int size)
{
	return tab;
}

int*	merge(int *tab1, int size1, int *tab2, int size2)
{
	return tab1;
}
void	ft_sort_int_tab(int *tab, int size)
{
	int s_p_1;
	int s_p_2;
	
	if (size < 2)
		return ;
	
	s_p_1 = size / 2;
	if (size %  2 == 0)
		s_p_2 = s_p_1;
	else
		s_p_2 = s_p_1 + 1;
	
	tab = merge(sort(tab, s_p_1 ), s_p_1, sort(&tab[s_p_1], s_p_2), s_p_2);
}

int	main(void)
{
	return (0);
}
