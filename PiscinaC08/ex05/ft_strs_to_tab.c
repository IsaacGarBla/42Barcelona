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
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

void	*ft_free_tabs(t_stock_str *tabs)
{
	int		i;

	i = 0;
	while (tabs[i].str != NULL)
	{
		free(tabs[i].copy);
		i++;
	}
	free(tabs);
	return (NULL);
}

t_stock_str	*ft_add_string(t_stock_str *tab, char *str)
{
	tab->size = ft_strlen(str);
	tab->copy = malloc((tab->size + 1) * sizeof(char));
	if (tab->copy == NULL)
		return (NULL);
	tab->str = str;
	ft_strcpy(tab->copy, str);
	return (tab);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*tabs;
	int				i;

	tabs = malloc((ac + 1) * sizeof(t_stock_str));
	if (tabs == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tabs[i].str = NULL;
		if (ft_add_string(&tabs[i], av[i]) == NULL)
			return (ft_free_tabs(tabs));
		i++;
	}
	tabs[i].str = NULL;
	return (tabs);
}

#include <stdio.h>

int	main(void)
{
	char			*str[]
		= {"Cadena 1", "Cadena 21", "Cadena 321", "Cadena 4321"};
	t_stock_str		*tabs;

	tabs = ft_strs_to_tab(4, str);
	ft_show_tab(tabs);
	ft_free_tabs(tabs);
	return (1);
}
