/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:00:47 by igarcia-          #+#    #+#             */
/*   Updated: 2026/03/22 16:00:49 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

char	*ft_n_zero(int n_zero, char *dst)
{
	int	x;

	dst[0] = '1';
	x = 1;
	while (x <= n_zero)
	{
		dst[x] = '0';
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

int	ft_is_zero(char *src)
{
	int	x;

	x = 0;
	while (src[x])
		if (src[x++] != '0')
			return (0);
	return (1);
}

int	ft_solve_less100(t_dict *dict, int v_num, t_solve *sol)
{
	char	tmp[MAX_LONG_KEY];

	if (v_num / 20 == 0)
	{
		if (find_value(dict, ft_itoa(v_num, tmp),
				(*sol).words[(*sol).size++]) == NULL)
			return (0);
	}
	else
	{
		if (find_value(dict, ft_itoa((v_num / 10) * 10, tmp),
				(*sol).words[(*sol).size++]) == NULL)
			return (0);
		if (v_num % 10 != 0)
		{
			if (find_value(dict, ft_itoa(v_num % 10, tmp),
					(*sol).words[(*sol).size++]) == NULL)
				return (0);
		}
	}
	return (1);
}

int	ft_solve(t_dict *dict, char *num, int n_zero, t_solve *sol)
{
	char	tmp[MAX_LONG_KEY];
	int		v_num;

	v_num = ft_atoi(num);
	if (v_num == 0)
		return (1);
	if (v_num / 100 != 0)
	{
		ft_solve(dict, ft_itoa(v_num / 100, tmp), 0, sol);
		if (find_value(dict, ft_itoa(100, tmp),
				(*sol).words[(*sol).size++]) == NULL)
			return (0);
		ft_solve(dict, ft_itoa(v_num % 100, tmp), 0, sol);
	}
	else if (!ft_solve_less100(dict, v_num, sol))
		return (0);
	if (n_zero != 0)
	{
		ft_n_zero(n_zero, tmp);
		if (find_value(dict, tmp, (*sol).words[(*sol).size++]) == NULL)
			return (0);
	}
	return (1);
}

int	ft_resolve_number(t_dict *dict, char *num, t_solve *sol)
{
	int		n_block3;
	char	tmp[4];

	if (ft_is_zero(num))
		return (find_value(dict, "0", (*sol).words[(*sol).size++]) != NULL);
	else
	{
		n_block3 = ft_strlen(num) / 3;
		if (ft_strlen(num) % 3 != 0)
		{
			ft_strncpy(tmp, &num[0], ft_strlen(num) % 3);
			if (!ft_solve(dict, tmp, n_block3 * 3, sol))
				return (0);
		}
		while (n_block3 > 0)
		{
			ft_strncpy(tmp, &num[ft_strlen(num) - n_block3 * 3], 3);
			if (!ft_solve(dict, tmp, (n_block3 - 1) * 3, sol))
				return (0);
			n_block3--;
		}
	}
	return (1);
}
