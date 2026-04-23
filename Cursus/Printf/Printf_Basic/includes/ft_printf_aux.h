/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:19:19 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 01:57:42 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_AUX_H
# define FT_PRINTF_AUX_H

# include "libft.h"
# include <stdarg.h>

unsigned int	ft_putchar_pf(char c);
unsigned int	ft_putstr_pf(char *s);
unsigned int	ft_putnbr_pf(int n);
unsigned int	ft_putnbr_base_pf(unsigned long long n, char *base);
unsigned int	ft_putptr_pf(void *ptr);

#endif
