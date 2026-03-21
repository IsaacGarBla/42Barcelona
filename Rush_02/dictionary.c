/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:09 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/21 12:43:32 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_ENTRIES
# define MAX_ENTRIES 128
#endif

#ifndef MAX_LONG_KEY
# define MAX_LONG_KEY 128
#endif

#ifndef MAX_LONG_VALUE
# define MAX_LONG_VALUE 128
#endif

#include <stdlib.h>

typedef struct s_dict
{
	char	**keys;
	char	**values;
	int		size;
}	t_dict;

// Reserves memory to store the dictionary.
// If there isany error, returns 0.
// Otherwise, returns 1.

int	create_dict(t_dict *dictionary)
{
	(*dictionary).keys = malloc (sizeof(char *) * MAX_ENTRIES);
	if ((*dictionary).keys == NULL)
		return (0);
	(*dictionary).values = malloc (sizeof(char *) * MAX_ENTRIES);
	if ((*dictionary).values == NULL)
	{
		free((*dictionary).keys);
		return (0);
	}
	return (1);
}

void	destroy_dict(t_dict *dictionary)
{
	int	x;

	if ((*dictionary).keys != NULL)
	{
		x = 0;
		while (x < MAX_ENTRIES)
		{
			free((*dictionary).keys[x]);
			free((*dictionary).values[x]);
			x++;
		}
		free((*dictionary).keys);
		free((*dictionary).values);
	}
}
