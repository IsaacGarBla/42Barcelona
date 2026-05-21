/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_f_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:31:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 15:20:11 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTNBR_F_BONUS_H
# define FT_PRINTNBR_F_BONUS_H

# include "ft_putnchar_bonus.h"
# include "ft_printf_bonus.h"

int		ft_unsigned_nbr_dig(unsigned long long n, int base);
void	ft_put_unsigned_nbr_base(unsigned long long n, char *base, int len);

#endif
