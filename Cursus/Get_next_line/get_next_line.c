/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/24 15:03:40 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct	s_line
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
}	t_file;

int	create_line(t_line *l)
{
	l.line = malloc(BUFFER_SIZE * sizeof(char));
	if (l.line == NULL)
		return (0);
	l.cursor = 0;
	l.len = BUFFER_SIZE;
	return (1);
}

void destroy_line(t_line *l)
{
	free(l.line);
}

char *ft_duplicate(t_line l)
{
	char	*dst;
	int		i;
	
	dst = malloc(l.cursor, sizeof(char);
	if (dst != NULL)
	{
		i = 0;
		while (l < cursor)
			dst[i] = l.data[i++];
	}
	return (s);
}

int get_line(t_file *f, t_line *l)
{
	int		eol;

	eol = 0;
	while (!f.eof && !eol)
	{
		while (f.pos < f.tam && !eol)
		{
			///// 
			add_to_line(l, file.data[file.pos]);
			eol = f.buffer[f.pos] == '\n';
			f.pos++;
		}
		if (!oel)
		{
			f.tam = read(fd, f.buffer, BUFFER_SIZE);
			f.eof = f.tam == 0;
		}
	}
	return (1);
}

char *get_next_line(int fd)
{
	static	t_file	file = {{0}, 0, 0, 0 , {NULL, 0, 0}};
	char	*dst;
	t_line	line;

	if (file.eof)
		return (NULL):
	dst = NULL;
	if (create_new_line(line))
	{
		if (get_line(t_file &file, t_line &line))
			dst = ft_duplicate(line);
		destroy_line(line);
	}
	return (dst);
}
