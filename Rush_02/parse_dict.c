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

int     skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

void	parse_line(char *line, char *key, char *value)
{
	int		i;
	int		j;

	i = skip_spaces(line, 0);
	if (line[i] < '0' || line[i] > '9') // Error: No comença per número
		return ;
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
		num[j++] = line[i++];
	num[j] = '\0';
	i = skip_spaces(line, i);
	if (line[i++] != ':') // Error: No hi ha separador
		return ;
	i = skip_spaces(line, i);
	if (line[i] == '\0' || line[i] == '\n') // Error: No hi ha text
		return ;
	j = 0;
	while (line[i] && line[i] != '\n')
		text[j++] = line[i++];
	text[j] = '\0';
	// Aquí ja tens 'num' i 'text' nets i validats
}

int read_and_process(t_dict *dict, int fd)
{
	char	line[4096];
	char	c;
	int		i;
    int     n_entry;

	i = 0;
    n_entry = 0;
	while (read(fd, &c, 1) > 0)
	{
		line[i++] = c;
		if (c == '\n' || i >= 4096 -1 )
		{
			line[i] = '\0';
			if (!parse_line(line), entry))
                return (0);
            entry++;
			i = 0;
		}
	}
    return (1);
}

// Gets the diccionary from the file 'f_name'.
// Returns 1 if the dictionary is correct.
// Oterwise, returns 0.
int	get_dictionary(t_dict *dict, char *f_name)
{
	char	c;
	int		fd;
	int		result;

	fd = open(f_name, O_RDONLY);
	if (!fd)
		return (0);
    result = read_and_process(dict, fd)    
	fclose(fd);
    return (result)
}