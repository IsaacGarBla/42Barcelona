/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:50:20 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 19:50:22 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>
# include "string.h"
# include "dictionary.h"
# include "convert.h"
# include "solution.h"

int		ft_resolve_number(t_dict *dict, char *num, t_solve *sol);

#endif
