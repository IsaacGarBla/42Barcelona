/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia- <marvin@42.fr>  >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:23:11 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 10:54:57 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

void	ft_rev_str(char *str)
{
	int		inici;
	int		fin;
	char	temp;

	inici = 0;
	fin = ft_strlen(str) - 1;
	while (inici <= ft_strlen(str) / 2 -1)
	{
		temp = str[inici];
		str[inici] = str[fin];
		str[fin] = temp;
		inici++;
		fin--;
	}
}

void	ft_strncpy(char *destino, const char *origen, int n)
{
	int	i;

	i = 0;
	while (i < n && origen[i] != '\0')
	{
		destino[i] = origen[i];
		i++;
	}
	destino[i] = '\0';
}
