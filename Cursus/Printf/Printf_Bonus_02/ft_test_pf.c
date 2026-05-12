/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:20:34 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/09 05:01:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	
	char	s[] = "Hello world.";
	int		le_pf;
	int		le_ft_pf;
	

	// Un char (c)
	ft_printf("## A char (c).\n\n");
	le_ft_pf = ft_printf("FT -> [%c]\n", 'A');
	le_pf = printf("PF -> [%c]\n", 'A');
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un string (s)
	ft_printf("## A string (s).\n\n");
	le_ft_pf = ft_printf("FT -> [%s]\n", s);
	le_pf = printf("PF -> [%s]\n", s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un puntero (p)
	ft_printf("## A pointer (p) format HEX.\n\n");
	le_ft_pf = ft_printf("FT -> [%p]\n", &s);
	le_pf = printf("PF -> [%p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%p]\n", NULL);
	le_pf = printf("PF -> [%p]\n", NULL);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	// Un numero decimal (d)
	ft_printf("## A decimal number (d).\n\n");
	le_ft_pf = ft_printf("FT -> [%d]\n", INT_MAX);
	le_pf = printf("PF -> [%d]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%d]\n", INT_MIN);
	le_pf = printf("PF -> [%d]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%d]\n", 0);
	le_pf = printf("PF -> [%d]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un entero en base 10 (i)
	ft_printf("## A integer base 10 (i).\n\n");
	le_ft_pf = ft_printf("FT -> [%i]\n", INT_MAX);
	le_pf = printf("PF -> [%i]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%i]\n", INT_MIN);
	le_pf = printf("PF -> [%i]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%i]\n", 0);
	le_pf = printf("PF -> [%i]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	
	// Un numero decimal sin signo (u)
	ft_printf("A unsigned decimal (u).\n\n");
	le_ft_pf = ft_printf("FT -> [%u]\n", INT_MAX);
	le_pf = printf("PF -> [%u]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%u]\n", INT_MIN);
	le_pf = printf("PF -> [%u]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%u]\n", 0);
	le_pf = printf("PF -> [%u]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un numero hexadecimal en minusculas (x)
	ft_printf("A HEX number lowercase (x).\n\n");
	le_ft_pf = ft_printf("FT -> [%x]\n", INT_MAX);
	le_pf = printf("PF -> [%x]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%x]\n", INT_MIN);
	le_pf = printf("PF -> [%x]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%x]\n", 42);
	le_pf = printf("PF -> [%x]\n",  42);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	
	// Un numero hexadecimal en mayusculas (X)
	ft_printf("A HEX number uppercase (X).\n\n");
	le_ft_pf = ft_printf("FT -> [%X]\n", INT_MAX);
	le_pf = printf("PF -> [%X]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%X]\n", INT_MIN);
	le_pf = printf("PF -> [%X]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%X]\n", 42);
	le_pf = printf("PF -> [%X]\n", 42);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// El caracter % (%)
	ft_printf("The %% character.\n\n");
	le_ft_pf = ft_printf("FT -> %%%%%\n");
	le_pf = printf("PF -> %%%%%\n");
	printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	
	// Cadena nula
	ft_printf("## Cadena nula\n\n");
	le_ft_pf = ft_printf(NULL);
	le_pf = printf(NULL);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
}

