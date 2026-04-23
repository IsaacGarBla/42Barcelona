/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:31:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 03:04:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTSTR_PF_H
# define FT_PUTSTR_PF_H

# include <unistd.h>
# include "ft_flags.h"
# include "libft.h"
# include "ft_putnchar.h"

unsigned int	ft_putstr_pf(char *s, t_flags flags);

#endif
