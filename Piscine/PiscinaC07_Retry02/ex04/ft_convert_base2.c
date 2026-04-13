/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:10:20 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/23 18:10:24 by igarcia-         ###   ########.fr       */
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
		return (i);
	return (-1);
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
	int		i;
	int		signo;
	long	valor;
	int		b;

	i = 0;
	signo = 1;
	valor = 0;
	b = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signo *= -1;
	while (str[i] && ft_find_digit(base, str[i]) != -1)
	{
		valor = valor * b
			+ ft_find_digit(base, str[i]);
		i++;
	}
	valor = valor * signo;
	if (valor < -2147483648 || valor > 2147483647)
		return (0);
	return ((int) valor);
}
