/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:58 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 17:50:57 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		256
# endif

# define BUFFER_SIZE_LINE	256

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_line
{
	char	*data;
	size_t	cursor;
	size_t	len;
}	t_line;

typedef struct s_file
{
	char	buffer[BUFFER_SIZE];
	size_t	b_tam;
	size_t	b_pos;
	int		eof;
	int		fd;
}	t_file;

char	*get_next_line(int fd);

#endif
