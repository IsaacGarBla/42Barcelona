/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:47:15 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/25 16:47:19 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;


t_stock_str *ft_free_tabs(t_stock_str *tabs, int nt)
{
}

int ft_add_str_to_tab(t_stock_str *tab, char *str, int pos)
{
	int		i;
	
	tabs = malloc((ac + 1) * sizeof(t_stock_str))
	if (tabs == NULL)
		return (NULL);
	return (tabs);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*tabs;
	int				i;
	
	tabs = malloc((ac + 1) * sizeof(t_stock_str))
	if (tabs == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (ft_add_strin(&tabs[i], av[0], i) == NULL)
			return (ft_free_tabs(tabs));
	}
}
