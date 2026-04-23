/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_f.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:31:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 02:40:48 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTNBR_F_H
# define FT_PRINTNBR_F_H

# include <unistd.h>
# include "ft_flags.h"
# include "ft_putnchar.h"
# include "libft.h"

int		ft_unsigned_nbr_dig(unsigned long long n, int base);
void	ft_put_unsigned_nbr_base(unsigned long long n, char *base, int len);

#endif
