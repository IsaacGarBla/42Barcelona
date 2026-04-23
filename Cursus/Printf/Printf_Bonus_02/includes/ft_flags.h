/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:14:31 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 05:13:11 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

#endif