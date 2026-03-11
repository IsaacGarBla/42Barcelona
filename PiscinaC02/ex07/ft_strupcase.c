/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:23:51 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/11 13:24:00 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char 	*tf_upcase(char *str)
{
	*str = 'A' + *str - 'a';
}

char	*ft_strupcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'a' && str[pos] <= 'z')
			
		pos++;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Pasar a mayusculas.";

	printf("Antes  : '%s'\n", str);
	printf("Despues: '%s'\n", ft_strupcase(str));
	return (0);
}*/
