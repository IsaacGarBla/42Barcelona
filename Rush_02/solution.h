/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:58:36 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 20:58:38 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# define MAX_WORDS 2048
# define MAX_LONG_WORD 256

# include <stdlib.h>
# include "print.h"

typedef struct s_solve
{
	char	**words;
	int		size;
}	t_solve;

int		add_space_for_solution(t_solve *sol);
int		free_space_for_solution(t_solve *sol);
void	ft_print_sol(t_solve *sol);

#endif
