/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:45:20 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/17 15:45:26 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	ft_find_char(char *str, unsigned char to_find)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != to_find)
		i++;
	if (str[i] == to_find)
		return (i + 1);
	return (0);
}

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
	return (x > 1);
}

int	ft_parse_number(char *str, char *base, int *ini, int *fin)
{
	int	i;
	int	j;
	int	signo;

	i = 0;
	signo = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signo *= -1;
	j = i;
	while (str[j] && ft_find_char(base, (unsigned char) str[j]))
		j++;
	if (j > i)
	{
		*ini = i;
		*fin = j - 1;
		return (signo);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ini;
	int	fin;
	int	valor;
	int	ini_base;

	if (!ft_check_base(base))
		return (0);
	if (!ft_parse_number(str, base, &ini, &fin))
		return (0);
	ini_base = 1;
	while (fin >= ini)
	{
		valor = valor
			+ ini_base * (ft_find_char(base, (unsigned char) str[fin]) - 1);
		ini_base = ini_base * ft_strlen(base);
		fin--;
	}
	return (valor * ft_parse_number(str, base, &ini, &fin));
}

#include <stdio.h>

int	main(void)
{
	char	*str = "  ---+--+1524";
	char	*base = "0123456789";

	printf("El valor entero de '%s' en base '%s' es: %d.\n", str,
		base, ft_atoi_base(str, base));
	return (0);
}

