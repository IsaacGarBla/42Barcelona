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
	while (nbr[x])
	{
		if (!ft_find_digit(base, nbr[x]))
			return (0);
		x++;
	}
	return (1);
}

int ft_n_char(int nbr, int b)
{
	int	d;
	long n;

	d = 0;
	if (nbr < 0)
	{	
		d = 1;
		nbr =  nbr * -1;
	}
	while (nbr > b )
	{
		d++;
		nbr = nbr / b;
	}
	return (++d);
}

/*char *ft_itoa(int nbr, char *base)
{
	int b;
	
	b = ft_strlen(base); // con esto obtenemos la base.
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char *dst;
	
	if (!ft_check_base(base_from) || !ft_check_base(base_to)
		|| !ft_check_number_base(nbr, base_from))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	// Ahora hay que convertir el numero a la nueva base.
}*/

#include <stdio.h>

int	main(void)
{
	int n = -123123;
	int b = 10;
	
	printf("El numero %d en base %d tiene %d caracteres.\n", n,
		b, ft_n_char(n, b));
}


