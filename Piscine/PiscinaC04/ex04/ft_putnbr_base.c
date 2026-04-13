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
	long	nbrl;

	b = ft_check_base(base);
	if (b < 2)
		return ;
	nbrl = nbr;
	if (nbrl < 0)
	{
		write(1, "-", 1);
		nbrl *= -1;
	}
	if (nbrl < b)
		write(1, &base[nbrl], 1);
	else
	{
		ft_putnbr_base(nbrl / b, base);
		write(1, &base[nbrl % b], 1);
	}
}

/*#include <stdio.h>

int	main(int narg, char **argv)
{
	int		v1 = -2147483648;
	int		v2 = 2147483647;
	int		v3 = -2147483647;
	int		v4 = 0;
	int		v5 = -125683;
	int		v6 = 683;

	if (narg != 2)
		return (0);
	printf("El valor %d en base '%s':\n", v1, argv[1]);
	printf("\n");
	ft_putnbr_base(v1, argv[1]);
	printf("\n");
	printf("El valor %d en base '%s':\n", v2, argv[1]);
	printf("\n");
	ft_putnbr_base(v2, argv[1]);
	printf("\n");
	printf("El valor %d en base '%s':\n", v3, argv[1]);
	printf("\n");
	ft_putnbr_base(v3, argv[1]);
	printf("\n");
	printf("El valor %d en base '%s':\n", v4, argv[1]);
	printf("\n");
	ft_putnbr_base(v4, argv[1]);
	printf("\n");
	printf("El valor %d en base '%s':\n", v5, argv[1]);
	printf("\n");
	ft_putnbr_base(v5, argv[1]);
	printf("\n");
	printf("El valor %d en base '%s':\n", v6, argv[1]);
	printf("\n");
	ft_putnbr_base(v6, argv[1]);
	printf("\n");
	return (0);
}*/
