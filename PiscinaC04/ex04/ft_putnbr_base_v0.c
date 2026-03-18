/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:16:22 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/18 01:54:12 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	x;
	int	j;

	x = 0;
	while (base[x])
	{
		if (!(base[x] > 32 && base[x] < 127 && base[x]
				!= '+' && base[x] != '-'))
			return (0);
		j = 0;
		while (j < x)
		{
			if (base[j] == base[x])
				return (0);
			j++;
		}
		x++;
	}
	return (x);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;

	b = ft_check_base(base);
	if (b < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < b)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_base(nbr / b, base);
		write(1, &base[nbr % b], 1);
	}
}

/*#include <stdio.h>

int	main(int narg, char **argv)
{
	int		v = -125683;

	if (narg != 2)
		return (0);
	printf("El valor %d en base '%s':", v, argv[1]);
	printf("\n");
	printf("\n");
	ft_putnbr_base(v, argv[1]);
	printf("\n");
	return (0);
}

/*int	ft_char_base_ok(char c)
{
	if ((c > 32 && c < 127 && c != '+' && c != '-'))
		return (1);
	else
		return (0);
}

char	*ft_strnstr(char *str, char *to_find, int pos)
{
	int	x;
	int	y;

	x = 0;
	while (str[x] && x < pos)
	{
		if (str[x] == to_find[0])
		{
			y = 1;
			while (str[x + y] && to_find[y]
				&& str[x + y] == to_find[y])
				y++;
			if (!to_find[y])
				return (&str[x]);
		}
		x++;
	}
	return (NULL);
}

int	base_ok(char *base)
{
	int		b;
	char	c[2];

	c[1] = '\0';
	b = 0;
	while (base[b])
	{
		if (!ft_char_base_ok(base[b]))
			return (0);
		c[0] = base[b];
		if (ft_strnstr(base, c, b) != NULL)
			return (0);
		b++;
	}
	if (b <= 1)
		return (0);
	else
		return (b);
}
*/
