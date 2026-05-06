/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:18:49 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 18:07:03 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	set_error(t_error *error, t_error_code error_code)
{
	error->error_code = error_code;
	error->error = true;
}

void	reset_error(t_error *error)
{
	error->error_code = OK;
	error->error = false;
}

bool	has_error(t_error *error)
{
	return (error->error);
}

void	error_exit(t_error *error)
{
	if (error->error)
	{
		write(1, "Error\n", 6);
		ft_printf("Error code: %d\n", error->error_code);
		exit(error->error_code);
	}
}
