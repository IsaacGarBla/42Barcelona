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

int	ft_find_digit(char *str, unsigned char to_find)
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
	while (str[j] && ft_find_digit(base, (unsigned char) str[j]))
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
	int		ini;
	int		fin;
	long	valor;
	int		b;
	int		signo;

	if (!ft_check_base(base))
		return (0);
	signo = ft_parse_number(str, base, &ini, &fin);
	if (!signo)
		return (0);
	b = ft_strlen(base);
	valor = 0;
	while (ini <= fin)
	{
		valor = valor * b
			+ ft_find_digit(base, (unsigned char) str[ini]) - 1;
		ini++;
	}
	valor = valor * signo;
	if (valor < -2147483648 || valor > 2147483647)
		return (0);
	return ((int) valor);
}

/*#include <stdio.h>

int	main(int nargs, char **args)
{

	if (nargs != 3)
	{
		printf("Numero de argumentos erroneso.\n");
		return (0);
	}		
	printf("El valor entero de '%s' en base '%s' es: %d.\n", args[1],
		args[2], ft_atoi_base(args[1], args[2]));
	return (1);
}*/
