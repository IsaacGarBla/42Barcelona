/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:31:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 04:42:13 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBR_PF_H
# define FT_PUTNBR_PF_H

# include <unistd.h>
# include "ft_flags.h"
# include "ft_putnchar.h"
# include "libft.h"

int				ft_ndigits_signed(long long n, int base);
int				ft_ndigits_unsigned(unsigned long n, int base);
unsigned int	ft_putnbr_pf(int n, t_flags flags);
unsigned int	ft_putnbr_base_pf(unsigned long long n,
					char *base, t_flags flags);

#endif
