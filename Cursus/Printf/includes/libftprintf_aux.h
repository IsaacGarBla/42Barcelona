/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_aux.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:19:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 01:57:42 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_AUX_H
# define LIBFTPRINTF_AUX_H

# include "libft.h"
# include <stdarg.h>

void	ft_putchar_pf(char c, int fd, int *len);
void	ft_putstr_pf(char *s, int fd, int *len);
void	ft_putnbr_pf(int n, int fd, int *len);
void	ft_putnbr_base_pf(unsigned long long n, char *base, int fd, int *len);
void	ft_putptr_pf(void *ptr, int fd, int *len);

#endif