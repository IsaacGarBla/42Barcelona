/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:02:15 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/13 00:55:43 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_init_str(char *str, char c, unsigned int size)
{
	unsigned int x;

	x = 0;
	while (x < size)
	{
		str[x] = c;
		x++;
	}
	str[x] = '\0';

}

void	ft_long_to_char_baseX_r(char *str, unsigned long num, unsigned int base, int digits)
{
	char	*dig_hex;

	dig_hex = "0123456789abcdef";
	if (num < base)
	{
		str[digits - 1] = dig_hex[num];
		return ;
	}
	str[digits - 1] = dig_hex[num % base];
	digits--;
	ft_long_to_char_baseX_r(str, num / base, base, digits);
	return ;
}

void	ft_long_to_char_baseX(char *str, unsigned long num, unsigned int base, int digits)
{
	ft_init_str(str, '0', digits);
	ft_long_to_char_baseX_r(str, num , base, digits);
	return ;
}

void	ft_read_block_memory(char *addr, char *dest, int size)
{
	while (size > 0)
	{
		*dest = *addr;
		dest++;
		addr++;
		size--;
	}
}

void	ft_print_addr_hex(long addr)
{
	char buffer[17];

	ft_long_to_char_baseX(buffer, addr, 16, 16);
	ft_putstr(buffer);
	ft_putstr(": ");
}

void	ft_print_char_hex(char *src, int size)
{
	char buffer[3];
	int x;

	x = 0;
	while (x < 16)
	{
		if (x < size)
		{
			ft_long_to_char_baseX(buffer,(unsigned char) src[x], 16, 2);
			ft_putstr(buffer);	
		}
		else
			ft_putstr("  ");	
		if (x && x % 2) 
			ft_putstr(" ");
		x++;
	}
}

void	ft_print_char_char(char *src, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (ft_char_is_printable(src[x]))
			ft_putchr(src[x]);
		else	
			ft_putchr('.');
		x++;
	}
}

void	ft_print_line(long addr, char *src, int size)
{
	ft_print_addr_hex(addr);
	ft_print_char_hex(src, size);
	ft_print_char_char(src, size);
	ft_putstr("\n");
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	block[16];
	char	*pointer;

	pointer = addr;
	while (size > 16)
	{
		ft_read_block_memory(pointer, block, 16);
		ft_print_line((long) pointer, block, 16);
		size = size -16;
		pointer = pointer + 16;
	}
	if (size != 0)
	{
		ft_read_block_memory(pointer, block, size);	
		ft_print_line((long) pointer, block, size);
	}
	return addr;
}

int	main(void)
{
	char *c="asdasfv asv a\tsga\n\n\nsdf asgas \n";

	ft_print_memory((void*) c, 250);
}

