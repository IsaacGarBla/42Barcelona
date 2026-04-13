/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:01:25 by didguill          #+#    #+#             */
/*   Updated: 2026/03/25 00:13:05 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/read_file.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_strjoin(char *s1, const char *s2);
static void	ft_strcat(char *dest, const char *src);

char	*read_file(int fd)
{
	char	buffer[1024];
	char	*file;
	int		bytes_read;
	//int		total_size;

	file = NULL;
	//total_size = 0;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		file = ft_strjoin(file, buffer);
		if (!file)
			return (NULL);
		//total_size += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (bytes_read < 0)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

static char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strcat(joined, s1);
	ft_strcat(joined, s2);
	free(s1);
	return (joined);
}

static void	ft_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}
