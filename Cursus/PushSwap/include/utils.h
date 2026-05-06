/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 14:36:30 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "data.h"
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"
# include "libftprintf.h"

int			ft_strcmp(const char *s1, const char *s2);
void		free_data(t_data *data);
bool		is_valid_int(const char *str, int *value);
char		**ft_split_full(char *str, char *charset);
char		*ft_strndup(char *s, int n);
void		free_split(char **split);
void		print_stack(t_stack *stack);
void		print_stats(t_data *ps);
void		sa(t_data *ps);
void		sb(t_data *ps);
void		ss(t_data *ps);
void		pa(t_data *ps);
void		pb(t_data *ps);
void		ra(t_data *ps);
void		rb(t_data *ps);
void		rr(t_data *ps);
void		rra(t_data *ps);
void		rrb(t_data *ps);
void		rrr(t_data *ps);

#endif /* UTILS_H */
