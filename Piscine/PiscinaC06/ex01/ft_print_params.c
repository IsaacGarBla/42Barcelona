/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:28:16 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 15:28:18 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		write(1, &str[x++], 1);
}

int	main(int nargv, char **argv)
{
	int	x;

	x = 1;
	while (x < nargv)
	{
		ft_putstr(argv[x]);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}
