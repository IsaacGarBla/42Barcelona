/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:40:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/19 19:40:49 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
		write(1, &str[x++], 1);
}

int	main(int narg, char **args)
{
	int	x;

	ft_sort_args(args, 1, narg);
	x = 1;
	while (x < narg)
	{
		ft_putstr(args[x]);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}
