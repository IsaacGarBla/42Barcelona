/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 14:37:08 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "error.h"
#include "init_data.h"
#include "parse_input.h"
#include "dispatch_strategy.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_data	ps;

	if (argc < 2)
		return (OK);
	init_data(&ps);
	if (has_error(&ps.error))
		error_exit(&ps.error);
	parse_input(&ps, argc, argv);
	if (has_error(&ps.error))
		error_exit(&ps.error);
	print_stats(&ps);
	dispatch_strategy(&ps);
	print_stats(&ps);
	free_data(&ps);
	return (OK);
}
