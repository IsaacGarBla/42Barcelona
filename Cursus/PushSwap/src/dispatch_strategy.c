/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:59:26 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/06 18:06:34 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatch_strategy.h"

static void	dispatch_complex(t_data *data)
{
	(void)data;
	ft_printf("Dispatching complex strategy...\n");
}

static void	dispatch_medium(t_data *data)
{
	(void)data;
	ft_printf("Dispatching medium strategy...\n");
}

static void	dispatch_simple(t_data *data)
{
	on2_insertion(data);
}

static void	dispatch_adaptive(t_data *data)
{
	if (data->disorder < 0.2)
		dispatch_simple(data);
	else if (data->disorder < 0.5)
		dispatch_medium(data);
	else
		dispatch_complex(data);
}

void	dispatch_strategy(t_data *data)
{
	if (data->strategy == STG_SIMPLE)
		dispatch_simple(data);
	else if (data->strategy == STG_MEDIUM)
		dispatch_medium(data);
	else if (data->strategy == STG_COMPLEX)
		dispatch_complex(data);
	else if (data->strategy == STG_ADAPTIVE || data->strategy == STG_NONE)
		dispatch_adaptive(data);
}
