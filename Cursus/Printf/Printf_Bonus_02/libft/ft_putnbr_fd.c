/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:27:09 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 16:28:45 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a number to a file descriptor.
 *
 * This function writes the integer n to the file descriptor fd.
 *
 * @param n The number to write.
 * @param fd The file descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln < 10)
		c = ln + '0';
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		c = (ln % 10) + '0';
	}
	write(fd, &c, 1);
}
