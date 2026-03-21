/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:44 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/21 12:13:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
//	if (argc == 2)
//	{
//		init(DEFAULT_DICT, argv[1]);
//	}
//	else if (argc == 3)
//	{
//		init(argv[1], argv[2]);
//	}
	ft_putstr("Argumentos correctos.\n");
	return (0);
}
