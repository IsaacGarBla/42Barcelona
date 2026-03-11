/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:46:00 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 13:46:04 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_upcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str = 'A' + *str - 'a';
	return (str);
}

int	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		ini_word;
	int		pos;

	pos = 0;
	ini_word = 0;
	while (str[pos] != '\0')
	{
		if (!ini_word && ft_is_alpha(str[pos]))
		{
			ft_upcase(&str[pos]);
			ini_word = 1;
		}
		else if (!ft_is_alpha(str[pos]))
			ini_word = 0;
		pos++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "asf AAA asdflkj asdf -asd+;jasdk  asd";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strcapitalize(str));
	return (0);
}*/
