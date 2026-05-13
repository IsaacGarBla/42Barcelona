/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:38 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 18:15:24 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		add_to_line(t_line *l, char c);
int		create_line(t_line *l);
void	destroy_line(t_line *l);
char	*ft_duplicate(t_line *l);

/**
 * @brief	Reads data from a file into the buffer of the file structure.
 * 
 * This function reads up to BUFFER_SIZE bytes from the file associated with the
 * file structure and stores it in the buffer. It updates the buffer size, end of
 * file status, and buffer position accordingly. If the read operation fails, it
 * sets the buffer size to 0 and returns 0. If the read operation is successful,
 * it returns 1.
 * 
 * @param f	A pointer to the file structure from which to read.
 * @return	1 if the read operation was successful, 0 otherwise.
 */
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

/**
 * @brief	Reads characters from the file buffer and adds them to the line until
 * 			a newline character is encountered or the end of the file is reached.
 * 
 * This function reads characters from the file buffer and adds them to the line
 * structure. It continues to read characters until it encounters a newline
 * character or reaches the end of the file. If it successfully reads characters,
 * it returns 1. Otherwise, it returns 0.
 * 
 * @param f	A pointer to the file structure from which to read.
 * @param l	A pointer to the line structure to which characters will be added.
 * @return	1 if characters were successfully read and added to the line, 
 * 			0 otherwise.
 */
int	get_one_line(t_file *f, t_line *l)
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

/**
 * @brief	Reads the next line from a file descriptor and returns it as a
 * 			string.
 * 
 * This function reads the next line from the file associated with the given
 * file descriptor and returns it as a string.
 * 
 * @param fd	The file descriptor from which to read the line.
 * @return		A pointer to the string containing the next line, or NULL if
 * 				an error occurs or the end of the file is reached.
 */
char	*get_next_line(int fd)
{
	static t_file	file[MAX_OPEN_FD];
	char			*dst;
	t_line			line;

	if (fd >= MAX_OPEN_FD)
		return (NULL);
	file[fd].fd = fd;
	if (BUFFER_SIZE <= 0 || file[fd].eof || file[fd].fd < 0)
		return (NULL);
	dst = NULL;
	if (create_line(&line))
	{
		if (get_one_line(&file[fd], &line))
			dst = ft_duplicate(&line);
		destroy_line(&line);
	}
	return (dst);
}
