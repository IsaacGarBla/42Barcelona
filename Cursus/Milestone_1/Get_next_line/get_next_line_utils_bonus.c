/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:25 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 18:17:20 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * This function copies n bytes from the memory area pointed to by src to the
 * memory area pointed to by dest. The memory areas must not overlap. Use
 * ft_memmove if the memory areas do overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/**
 * @brief	Adds a character to the line structure, resizing the line's data
 * 			buffer if necessary.
 *
 * This function adds a character to the line structure. If the line's data
 * buffer is full, it resizes the buffer to accommodate more characters.
 *
 * @param l	A pointer to the line structure.
 * @param c	The character to add to the line.
 * @return	1 if the character was added successfully, 0 otherwise.
 */
int	add_to_line(t_line *l, char c)
{
	char	*new_l;

	if (l->cursor == l->len -1)
	{
		new_l = malloc((l->len + BUFFER_SIZE_LINE) * sizeof(char));
		if (new_l == NULL)
			return (0);
		ft_memcpy(new_l, l->data, l->len);
		l->len += BUFFER_SIZE_LINE;
		free(l->data);
		l->data = new_l;
	}
	l->data[l->cursor] = c;
	l->cursor++;
	return (1);
}

/**
 * @brief	Creates a new line structure and initializes its members.
 * 
 * This function allocates memory for the line's data buffer and initializes
 * the line's cursor and length. If the memory allocation fails, it returns 0.
 * If the line is created successfully, it returns 1.
 * 
 * @param l	A pointer to the line structure to be created.
 * @return	1 if the line was created successfully, 0 otherwise.
 */
int	create_line(t_line *l)
{
	l->data = malloc(BUFFER_SIZE_LINE * sizeof(char));
	if (l->data == NULL)
		return (0);
	l->cursor = 0;
	l->len = BUFFER_SIZE_LINE;
	return (1);
}

/**
 * @brief	Destroys a line structure and frees its data buffer.
 * 
 * This function frees the memory allocated for the line's data buffer. The
 * caller is responsible for ensuring that the line structure itself is
 * properly managed and that this function is called when the line is no
 * longer needed to avoid memory leaks.
 * 
 * @param l	A pointer to the line structure to be destroyed.
 * @return	None.
 */
void	destroy_line(t_line *l)
{
	free(l->data);
}

/**
 * @brief	Duplicates a line structure and returns a pointer to the new line.
 * 
 * This function allocates memory for a new line structure and copies the
 * data from the original line structure to the new one. If the memory 
 * allocation fails, it returns NULL. If the line is duplicated successfully,
 * it returns a pointer to the new line structure.
 * 
 * @param l	A pointer to the line structure to be duplicated.
 * @return	A pointer to the duplicated line structure, or NULL if an error
 * 			occurs.
 */
char	*ft_duplicate(t_line *l)
{
	char	*dst;
	size_t	i;

	dst = malloc((l->cursor + 1) * sizeof(char));
	if (dst != NULL)
	{
		i = 0;
		while (i < l->cursor)
		{
			dst[i] = l->data[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
