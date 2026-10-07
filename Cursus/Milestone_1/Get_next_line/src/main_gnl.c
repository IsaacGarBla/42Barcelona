/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:10:25 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 18:11:17 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int narg, char **argv)
{
	int		fd;
	char	*line;
	int		n_lines;

	narg += 0;
	n_lines = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		n_lines++;
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
}
