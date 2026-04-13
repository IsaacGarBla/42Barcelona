/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:54:14 by didguill          #+#    #+#             */
/*   Updated: 2026/03/24 12:58:45 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_square
{
	int		size;
	int		x;
	int		y;
}	t_square;

typedef struct s_map
{
	int			x;
	int			y;
	char		empty_char;
	char		obstacle_char;
	char		full_char;
	char		**grid;
	t_square	biggest_square;
}	t_map;

# define ERROR -1
# define OK 0

#endif
