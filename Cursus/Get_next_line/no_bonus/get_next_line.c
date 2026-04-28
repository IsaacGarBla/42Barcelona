/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/29 00:31:58 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(t_file *f)
{
	int	bytes_read;

	bytes_read = read(f->fd, f->buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		f->b_tam = 0;
	else
		f->b_tam = bytes_read;
	f->eof = f->b_tam == 0;
	f->b_pos = 0;
	return (bytes_read != -1);
}

int	get_line(t_file *f, t_line *l)
{
	int	eol;
	int	read_char;

	eol = 0;
	read_char = 0;
	while (!f->eof && !eol)
	{
		while (f->b_pos < f->b_tam && !eol)
		{
			if (!add_to_line(l, f->buffer[f->b_pos]))
				return (0);
			eol = f->buffer[f->b_pos++] == '\n';
			read_char++;
		}
		if (!eol)
			if (!read_buffer(f))
				return (0);
	}
	return (read_char != 0);
}

char	*get_next_line(int fd)
{
	static t_file	file;
	char			*dst;
	t_line			line;

	file.fd = fd;
	if (BUFFER_SIZE <= 0 || file.eof || file.fd < 0)
		return (NULL);
	dst = NULL;
	if (create_line(&line))
	{
		if (get_line(&file, &line))
			dst = ft_duplicate(&line);
		destroy_line(&line);
	}
	return (dst);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int narg, char **argv)
{
	int		fd;
	char	*line;
	int		n_lines;

	narg += 0;
	n_lines = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		n_lines++;
		printf("Linea %d: <%s>", n_lines, line);
		free (line);
		line = get_next_line(fd);
	}
	printf("Número de líneas impresas: %d\n", n_lines);
}
*/