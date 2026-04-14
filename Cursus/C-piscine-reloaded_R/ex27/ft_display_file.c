/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:14:40 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/14 16:14:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

int	ft_show_file(char *f_name)
{
	int		fd;
	char	buffer[1024];
	int		n_char;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (0);
	n_char = read(fd, buffer, 1024);
	while (n_char > 0)
	{
		write(1, buffer, n_char);
		n_char = read(fd, buffer, 1024);
	}
	close(fd);
	return (n_char != -1);
}

int	main(int narg, char **argv)
{
	if (narg == 1)
		ft_putstr("File name missing.\n");
	else if (narg > 2)
		ft_putstr("Too many arguments.\n");
	else if (ft_show_file(argv[1]) == 0)
		ft_putstr("Cannot read file.\n");
	return (0);
}
