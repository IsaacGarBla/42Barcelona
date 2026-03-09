/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:47:29 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/06 13:47:35 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* Reverses the characters in a string. */

void	invert_string(char string[], int length)
{
	char	c_tmp;
	int		i_start;
	int		i_end;		

	i_start = 0;
	i_end = length - 1;
	while (i_start < i_end)
	{
		c_tmp = string[i_start];
		string[i_start++] = string[i_end];
		string[i_end--] = c_tmp;
	}
}

void	int_to_char(int number, char string[])
{
	int		i_digit;
	int		i_position;

	i_position = 0;
	if (number == 0)
	{
		string[0] = '0';
		string[1] = '\0';
		return ;
	}
	while (number > 0)
	{
		i_digit = number % 10;
		string[i_position++] = '0' + i_digit;
		number = number / 10;
	}
	string[i_position] = '\0';
	invert_string(string, i_position);
}

/* Write a string that finish with the char '\0' without knowing its lenght */
void	write_string(char string_to_write[])
{
	int		i_position;

	i_position = 0;
	while (string_to_write[i_position] != '\0')
	{
		write(1, &string_to_write[i_position], 1);
		i_position++;
	}
}

void	ft_putnbr(int nb)
{
	char	s_buffer[25];

	int_to_char (nb, s_buffer);
	write_string (s_buffer);
}

/* Program test

int	main(void)
{
	ft_putnbr(87559);
}

*/
