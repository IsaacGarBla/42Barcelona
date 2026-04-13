/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:56:50 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/23 17:56:54 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_check_base(char *base);
int	ft_find_digit(char *str, unsigned char to_find);
int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);

int	ft_check_number_base(char *nbr, char *base)
{
	int	x;

	x = 0;
	while (nbr[x] == ' ' || ((nbr[x] >= 9 && nbr[x] <= 13)))
		x++;
	while (nbr[x] == '+' || nbr[x] == '-')
		x++;
	while (nbr[x])
	{
		if (!ft_find_digit(base, nbr[x]))
			return (0);
		x++;
	}
	return (1);
}

int	ft_n_dig(long nbr, int b)
{
	int		d;

	d = 0;
	if (nbr < 0)
	{
		d++;
	}
	while (((nbr < 0) * (-nbr) + (nbr >= 0) * (nbr)) >= b)
	{
		d++;
		nbr = nbr / b;
	}
	return (++d);
}

char	*ft_itoa(int nbr, char *base)
{
	int		b;
	char	*res;
	int		x;
	long	nbr_l;

	b = ft_strlen(base);
	x = ft_n_dig(nbr, b);
	nbr_l = nbr;
	res = malloc(sizeof(char) * x + 1);
	if (res == NULL)
		return (NULL);
	res[x--] = '\0';
	if (nbr_l < 0)
	{
		res[0] = '-';
		nbr_l = nbr_l * -1;
	}
	while (nbr_l >= b)
	{
		res[x] = base[nbr_l % b];
		nbr_l = nbr_l / b;
		x--;
	}
	res[x] = base[nbr_l % b];
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;

	if (!ft_check_base(base_from) || !ft_check_base(base_to)
		|| (ft_check_number_base(nbr, base_from) == -1))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	return (ft_itoa(n, base_to));
}

/*#include <stdio.h>

int	main(int narg, char **argv)
{
	narg = 0;
	printf("El numero %s en base %s pasado a base %s es -> %s.\n",
		argv[1], argv[2], argv[3], ft_convert_base(argv[1], argv[2], argv[3]));
}*/
