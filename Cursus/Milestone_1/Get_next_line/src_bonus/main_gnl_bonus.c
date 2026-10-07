/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:10:25 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 18:18:00 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int narg, char **argv)
{
	int		fd[2];
	char	*line;
	int		n_lines;

	narg += 0;
	n_lines = 0;
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);
	line = get_next_line(fd[0]);
	while (line != NULL)
	{
		n_lines++;
		printf("%s", line);
		free(line);
		line = get_next_line(fd[0]);
	}
	n_lines = 0;
	line = get_next_line(fd[1]);
	while (line != NULL)
	{
		n_lines++;
		printf("%s", line);
		free(line);
		line = get_next_line(fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
}
