/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:46:00 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/12 01:21:29 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_char_to_upcase(char c)
{
	c = 'A' + c - 'a';
	return (c);
}

int	ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		en_word;
	int		pos;

	pos = 0;
	en_word = 0;
	while (str[pos] != '\0')
	{
		if (!en_word && ft_char_is_alpha(str[pos]))
		{
			if (!ft_char_is_uppercase(str[pos]))
				str[pos] = ft_char_to_upcase(str[pos]);
			en_word = 1;
		}
		else if (!ft_char_is_alpha(str[pos]))
			en_word = 0;
		pos++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "AsA aaA asdflkj asdf -asd+;jasdk  asd";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strcapitalize(str));
	return (0);
}*/
