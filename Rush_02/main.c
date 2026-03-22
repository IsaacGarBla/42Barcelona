/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:44 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 10:15:23 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "dictionary.h"

#define DEFAULT_DICT "data/numbers.dict"

void	ft_putstr(char *str);
int		check_arg(int argc, char **argv, char *default_dict);

int	main(int argc, char **argv)
{
	t_dict	dictionary;

	if (!check_arg(argc, argv, DEFAULT_DICT))
	{
		ft_putstr("Error\n");
		return (0);
	}

	ft_putstr("Argumentos correctos.\n");
	ft_putstr("Creamos diccionario.\n");
	if (!create_dict(&dictionary))
		ft_putstr("Error creando diccionario.\n");
	else
	{
		ft_putstr("Destruimos diccionario.\n");
		destroy_dict(&dictionary);
	}
	ft_putstr("Fin de programa.\n");
	return (0);
}
