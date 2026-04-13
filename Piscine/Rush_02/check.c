/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:34 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/21 12:15:41 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#ifndef BUF_SIZE
# define BUF_SIZE 4096
#endif

// Checks the string str.
// If it only contains digits,retunrs 1.
// Otherwise, returns 0.
int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Check if the dictionary file exists.
// If it exists retunrs 1, otherwise returns 0.
//ssize_t	bytes_read;
int	check_dict_file(char *dict)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		bytes_read;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, BUF_SIZE);
	if (bytes_read <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

// Check the input arguments (number and conten),
// - Less 2 arguments or more than 3 => Error, returns 0.
// Otherwise:
// - 2 arguments => Default dicctionary.
// - 3 arguments => Second argument is he new dicctionary.
// It checks if the dictionary exists and 
// if the string to translate has only digits.
// If two conditions are true, returns 1. Otherwise, returns 0.
int	check_arg(int narg, char **argv, char *default_dict)
{
	if (narg < 2 || narg > 3)
		return (0);
	if (narg == 2)
		if (!check_digits(argv[1]) || !check_dict_file(default_dict))
			return (0);
	if (narg == 3)
		if (!check_digits(argv[2]) || !check_dict_file(argv[1]))
			return (0);
	return (1);
}
