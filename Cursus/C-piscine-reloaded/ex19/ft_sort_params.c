/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:33:33 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/13 15:33:35 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchr(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int		x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

void	ft_swap(char **src, char **dst)
{
	char	*tmp;

	tmp = *src;
	*src = *dst;
	*dst = tmp;
}

void	ft_sort_args(char **args, int ini, int narg)
{
	int		x;
	int		y;

	x = ini;
	while (x < narg -1)
	{
		y = x + 1;
		while (y < narg)
		{
			if (ft_strcmp(args[x], args[y]) > 0)
				ft_swap(&args[x], &args[y]);
			y++;
		}
		x++;
	}
}

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

int	main(int narg, char **args)
{
	int	x;

	ft_sort_args(args, 1, narg);
	x = 1;
	while (x < narg)
	{
		ft_putstr(args[x]);
		ft_putchr('\n');
		x++;
	}
	return (0);
}*/
