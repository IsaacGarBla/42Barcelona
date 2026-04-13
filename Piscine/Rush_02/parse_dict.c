/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:07:16 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 11:17:58 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "string.h"

int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	parse_line(char *line, t_dict *dict, int entry)
{
	int		i;
	int		j;

	i = skip_spaces(line, 0);
	if (line[i] < '0' || line[i] > '9')
		return (0);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		(*dict).keys[entry][j++] = line[i++];
	(*dict).keys[entry][j] = '\0';
	i = skip_spaces(line, i);
	if (line[i++] != ':')
		return (0);
	i = skip_spaces(line, i);
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	j = 0;
	while (line[i] && line[i] != '\n')
		(*dict).values[entry][j++] = line[i++];
	(*dict).values[entry][j] = '\0';
	(*dict).size = (*dict).size + 1;
	return (1);
}

int	read_and_process(t_dict *dict, int fd)
{
	char	line[4096];
	char	c;
	int		i;
	int		n_entry;

	i = 0;
	n_entry = 0;
	while (read(fd, &c, 1) > 0)
	{
		line[i++] = c;
		if (c == '\n' || i >= 4096 -1)
		{
			line[i] = '\0';
			if (ft_strlen(line) > 1)
			{
				if (!parse_line(line, dict, n_entry))
					return (0);
				n_entry++;
			}
			i = 0;
		}
	}
	return (1);
}
