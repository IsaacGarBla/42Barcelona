/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:15:55 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/21 02:02:33 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_putstr_pf(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

unsigned int	ft_putnbr_pf(int n)
{
	long			ln;
	char			c;
	unsigned int	i;

	ln = n;
	i = 0;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = -ln;
		i++;
	}
	if (ln < 10)
		c = ln + '0';
	else
	{
		i = i + ft_putnbr_pf(ln / 10);
		c = (ln % 10) + '0';
	}
	write(1, &c, 1);
	i++;
	return (i);
}

unsigned int	ft_putnbr_base_pf(unsigned long long n, char *base)
{
	unsigned int	b;
	unsigned int	i;

	i = 0;
	b = ft_strlen(base);
	if (n >= b)
		i = ft_putnbr_base_pf(n / b, base);
	ft_putchar_pf(base[n % b]);
	i++;
	return (i);
}

unsigned int	ft_putptr_pf(void *ptr)
{
	unsigned long long	address;
	unsigned int		i;

	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	address = (unsigned long long) ptr;
	i = ft_putstr_pf("0x");
	i = i + ft_putnbr_base_pf(address, "0123456789abcdef");
	return (i);
}
