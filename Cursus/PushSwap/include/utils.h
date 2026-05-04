/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 19:36:00 by igarcia-         ###   ########.fr       */
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
t_status	error_exit(t_status status);
void		free_data(t_data *data);
bool        is_valid_int(const char *str, int *value);
char        **ft_split_full(char *str, char *charset);
int		    count_words(char *str, char *charset);
bool	    is_separator(char c, char *charset);
char	    *ft_strndup(char *s, int n);
void        free_split(char **split);
void        print_stacks(t_data *ps);

#endif /* UTILS_H */
