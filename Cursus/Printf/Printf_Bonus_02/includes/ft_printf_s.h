/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:31:13 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/22 03:04:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_S_H
# define FT_PRINTF_S_H

# include <unistd.h>
# include "ft_flags.h"
# include "libft.h"
# include "ft_putnchar.h"

unsigned int	ft_printf_s(char *s, t_flags flags);

#endif
