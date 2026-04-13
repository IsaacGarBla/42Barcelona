/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 10:04:43 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 11:18:31 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# define MAX_ENTRIES 256
# define MAX_LONG_KEY 256
# define MAX_LONG_VALUE 256

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dict
{
	char	**keys;
	char	**values;
	int		size;
}	t_dict;

int		create_dict(t_dict *dict);
void	destroy_dict(t_dict *dict);
int		get_dictionary(t_dict *dict, char *f_name);
char	*find_value(t_dict *dict, char *key, char *value);

#endif
