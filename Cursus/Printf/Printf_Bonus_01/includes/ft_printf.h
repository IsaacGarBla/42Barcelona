/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:36:03 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 03:48:15 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_flags.h"
# include "ft_putchar_pf.h"
# include "ft_putstr_pf.h"
# include "ft_putnbr_pf.h"
# include "ft_putptr_pf.h"

int	ft_printf(char const *format, ...);

#endif
