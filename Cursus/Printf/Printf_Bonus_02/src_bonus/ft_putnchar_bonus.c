/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 01:27:52 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/11 14:08:59 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnchar_bonus.h"

unsigned int	ft_putnchar(char c, unsigned int n, int fd)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
	return (i);
}
