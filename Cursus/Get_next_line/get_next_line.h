/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:58 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/24 15:04:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_N
# define GET_NEXT_LINE_N

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	256
#endif

# include <stdlib.h>

char *get_next_line(int fd);

#endif
