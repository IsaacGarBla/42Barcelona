/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:18 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 18:05:29 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libftprintf.h"
# include <stdbool.h>

typedef enum e_error_code
{
	OK = 0,
	ERROR_DUPLICATE_NUMBER = 1,
	ERROR_UNRECOGNIZED_ARGUMENT = 2,
	ERROR_DUPLICATE_STRATEGY = 3,
	ERROR_DUPLICATE_BENCHMARK = 4,
	ERROR_STACK_EMPTY = 5,
	ERROR_MEMORY = 6
}	t_error_code;

typedef struct s_error
{
	t_error_code	error_code;
	bool			error;
}	t_error;

void	set_error(t_error *error, t_error_code error_code);
void	reset_error(t_error *error);
bool	has_error(t_error *error);
void	error_exit(t_error *error);

#endif /* ERROR_H */
