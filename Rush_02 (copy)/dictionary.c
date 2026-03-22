/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:09 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 11:18:41 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "string.h"
#include "parse_dict.h"

int	add_space_for_entries(t_dict *dictionary)
{
	int	i;

	i = 0;
	while (i < MAX_ENTRIES)
	{
		(*dictionary).keys[i] = malloc (sizeof(char) * MAX_LONG_KEY);
		if ((*dictionary).keys[i] == NULL)
			return (0);
		(*dictionary).values[i] = malloc (sizeof(char) * MAX_LONG_VALUE);
		if ((*dictionary).values[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

// Reserves memory to store the dictionary.
// If there is any error, returns 0.
// Otherwise, returns 1.
int	create_dict(t_dict *dict)
{
	int	i;

	(*dict).keys = malloc (sizeof(char *) * MAX_ENTRIES);
	if ((*dict).keys == NULL)
		return (0);
	(*dict).values = malloc (sizeof(char *) * MAX_ENTRIES);
	if ((*dict).values == NULL)
	{
		free((*dict).keys);
		return (0);
	}
	i = 0;
	while (i < MAX_ENTRIES)
	{
		(*dict).keys[i] = NULL;
		(*dict).values[i] = NULL;
		i++;
	}
	if (!add_space_for_entries(dict))
	{
		destroy_dict(dict);
		return (0);
	}
	(*dict).size = 0;
	return (1);
}

// Gets the diccionary from the file 'f_name'.
// Returns 1 if the dictionary is correct.
// Oterwise, returns 0.
int	get_dictionary(t_dict *dict, char *f_name)
{
	int		fd;
	int		result;

	fd = open(f_name, O_RDONLY);
	if (!fd)
		return (0);
	result = read_and_process(dict, fd);
	close(fd);
	return (result);
}

// Release memory of the dicctionary
void	destroy_dict(t_dict *dict)
{
	int	x;

	if ((*dict).keys != NULL && (*dict).values != NULL)
	{
		x = 0;
		while (x < MAX_ENTRIES)
		{
			if ((*dict).keys[x] == NULL)
				free((*dict).keys[x]);
			if ((*dict).values[x] == NULL)
				free((*dict).values[x]);
			x++;
		}
	}
	if ((*dict).keys != NULL)
		free((*dict).keys);
	if ((*dict).values != NULL)
		free((*dict).values);
}

char	*find_value(t_dict *dict, char *key, char *value)
{
	int		x;

	x = 0;
	while (x < (*dict).size)
	{
		if (!ft_strcmp((*dict).keys[x], key))
		{
			ft_strcpy(value, (*dict).values[x]);
			return (value);
		}
		x++;
	}
	return (NULL);
}
