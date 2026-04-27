/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:03:25 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/24 15:03:28 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	create_line(t_line *l)
{
	l->data = malloc(BUFFER_SIZE_LINE * sizeof(char));
	if (l->data == NULL)
		return (0);
	l->cursor = 0;
	l->len = BUFFER_SIZE_LINE;
	return (1);
}

void	destroy_line(t_line *l)
{
	free(l->data);
}

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
	}
	return (dst);
}
