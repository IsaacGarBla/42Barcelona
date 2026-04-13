/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:27:06 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/13 15:27:08 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchr(char c);

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		ft_putchr(str[x++]);
}

/*#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

int	main(int nargv, char **argv)
{
	int	x;

	x = 1;
	while (x < nargv)
	{
		ft_putstr(argv[x]);
		ft_putchr('\n');
		x++;
	}
	return (0);
}*/
