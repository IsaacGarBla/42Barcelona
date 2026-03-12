/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:02:15 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 11:02:17 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_long_to_char_baseX_r(char *str, long num, int base, int digits)
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

void	ft_long_to_char_baseX(char *str, long num, int base, int digits)
{
	int	x;
	
	x = 0;
	while (x < digits)
		str[x++] = '0';
	ft_long_to_char_baseX_r(str, num , base, digits);
	return ;
}

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

void	ft_init_blank(char *src, int len)
{
	int i;
	
	i = 0;
	while (i < len - 1) 
		src[i++] = ' ';
	src[i] = '\0';
}

void	ft_print_line(long addr, char *src, int size)
{
	char	line[75];	
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	ft_init_blank(line, 75);	
	ft_long_to_char_baseX(&line[0], addr, 16, 16);
	line[16] = ':';
	line[17] = ' ';
	while (x < size)
	{
		ft_long_to_char_baseX(&line[18 + y], (long) src[x], 16, 2);
		y += 2;
		if (x && x % 2) 
			line[18 + y++] = ' ';
		if (ft_char_is_printable(src[x]))
			line[58 + x] = src[x];	
		else
			line[58 + x] = '.';
		x++;
	}
	ft_putstr(line);
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

#include <stdio.h>

int	main(void)
{
	char *c="adas\ndasdasdassdd;gjadf kas;f' as [dkjaksfhsadfsadfj askdfj as;ldfk jaskdlfj asdklffasdasdasd.$";
	
	ft_print_memory((void*) c, 120);

}

