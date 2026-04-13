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

#include "dictionary.h"
#include "print.h"
#include "check.h"
#include "solve.h"

#define DEFAULT_DICT "data/numbers.dict"

int		tf_resolve_number(t_dict *dict, char *num);

int	main(int narg, char **argv)
{
	t_dict	dictionary;
	t_solve	sol;

	if (!check_arg(narg, argv, DEFAULT_DICT))
		ft_putstr("Error\n");
	else if (create_dict(&dictionary))
	{
		add_space_for_solution(&sol);
		if (narg == 2)
		{
			if (!get_dictionary(&dictionary, DEFAULT_DICT)
				|| !ft_resolve_number(&dictionary, argv[1], &sol))
				ft_putstr("Dict Error\n");
			else
				ft_print_sol(&sol);
		}
		else if (!get_dictionary(&dictionary, argv[1])
			|| !ft_resolve_number(&dictionary, argv[2], &sol))
			ft_putstr("Dict Error\n");
		else
			ft_print_sol(&sol);
		free_space_for_solution(&sol);
		destroy_dict(&dictionary);
	}
	return (0);
}
