/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:15:55 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 02:02:33 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_pf(char c, int fd, int *len)
{
	write(fd, &c, 1);
	(*len)++;
}

void	ft_putstr_pf(char *s, int fd, int *len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
		(*len)++;
	}
}

void	ft_putnbr_pf(int n, int fd, int *len)
{
	long	ln;
	char	c;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
		(*len)++;
	}
	if (ln < 10)
		c = ln + '0';
	else
	{
		ft_putnbr_pf(ln / 10, fd, len);
		c = (ln % 10) + '0';
	}
	write(fd, &c, 1);
	(*len)++;
}

void	ft_putnbr_base_pf(unsigned long long n, char *base, int fd, int *len)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (n >= b)
		ft_putnbr_base_pf(n / b, base, fd, len);
	ft_putchar_pf(base[n % b], fd, len);
}

void	ft_putptr_pf(void *ptr, int fd, int *len)
{
	unsigned long long	address;

	if (!ptr)
	{
		ft_putstr_pf("(null)", 1, len);
		return ;
	}
	address = (unsigned long long) ptr;
	ft_putstr_pf("0x", fd, len);
	ft_putnbr_base_pf(address, "0123456789abcdef", fd, len);
}
