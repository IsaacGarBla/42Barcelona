/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:20:34 by igarcia-          #+#    #+#             */
/*   Updated: 2026/04/23 02:54:39 by igarcia-         ###   ########.fr       */
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
	ft_printf("## Char (c).\n\n");
	le_ft_pf = printf("FT -> [%c]\n", 'A');
	le_pf = printf("PF -> [%c]\n", 'A');
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un string (s)
	ft_printf("## String (s).\n\n");
	le_ft_pf = ft_printf("FT -> [%s]\n", s);
	le_pf = printf("PF -> [%s]\n", s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%s]\n", (char *) NULL);
	le_pf = printf("PF -> [%s]\n",(char *) NULL);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");


	// Un numero decimal (d)
	ft_printf("## Decimal (d).\n\n");
	le_ft_pf = ft_printf("FT -> [%d]\n", INT_MAX);
	le_pf = printf("PF -> [%d]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%d]\n", INT_MIN);
	le_pf = printf("PF -> [%d]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%d]\n", -1);
	le_pf = printf("PF -> [%d]\n",  -1);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");


	// Un entero en base 10 (i)
	ft_printf("## Integer base 10 (i).\n\n");
	le_ft_pf = ft_printf("FT -> [%i]\n", INT_MAX);
	le_pf = printf("PF -> [%i]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%i]\n", INT_MIN);
	le_pf = printf("PF -> [%i]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%i]\n", 0);
	le_pf = printf("PF -> [%i]\n", 0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	
	// Un numero decimal sin signo (u)
	ft_printf("Unsigned decimal (u).\n\n");
	le_ft_pf = ft_printf("FT -> [%u]\n", INT_MAX);
	le_pf = printf("PF -> [%u]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%u]\n", 0);
	le_pf = printf("PF -> [%u]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

/*

	// Un puntero (p)
	ft_printf("## Pointer (p).\n\n");
	le_ft_pf = ft_printf("FT -> [%p]\n", &s);
	le_pf = printf("PF -> [%p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%p]\n", NULL);
	le_pf = printf("PF -> [%p]\n", NULL);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");


	// Un numero hexadecimal en minusculas (x)
	ft_printf("HEX number lowercase (x).\n\n");
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
	ft_printf("HEX number uppercase (X).\n\n");
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
	ft_printf("The '%%' character (%%).\n\n");
	le_ft_pf = ft_printf("FT -> [%%]\n");
	le_pf = printf("PF -> [%%]\n");
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

*/
	// Bonus, flags -0.
	ft_printf("BONUS FLAGS.\n\n");

	// Char
	ft_printf("## Char.\n\n");
	le_ft_pf = printf("FT (5c) -> [%5c]\n", 'A');
	le_pf = printf("PF (5c) -> [%5c]\n", 'A');
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	
	// String
	ft_printf("## String.\n\n");
	le_ft_pf = ft_printf("FT (30s) -> [%30s]\n", s);
	le_pf = printf("PF (30s) -> [%30s]\n", s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
	
	ft_printf("## String.\n\n");
	le_ft_pf = ft_printf("FT (-30s) -> [%-30s]\n", s);
	le_pf = printf("PF (-30s) -> [%-30s]\n", s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	ft_printf("## String.\n\n");
	le_ft_pf = ft_printf("FT (-10.5s) -> [%-10.5s]\n", s);
	le_pf = printf("PF (-10.5s) -> [%-10.5s]\n", s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Decimals
	ft_printf("## Decimal.\n\n");
	le_ft_pf = ft_printf("FT (-20d) -> [%-20d]\n", INT_MAX);
	le_pf = printf("PF (-20d) -> [%-20d]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (20d) -> [%20d]\n", INT_MIN);
	le_pf = printf("PF (20d) -> [%20d]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (-10d) -> [%-10d]\n", 0);
	le_pf = printf("PF (-10d) -> [%-10d]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	ft_printf("## Decimal.\n\n");
	le_ft_pf = ft_printf("FT (+30d.) -> [%+30d.]\n", INT_MAX);
	le_pf = printf("PF (+30d.) -> [%+30d.]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+030d) -> [%+030d]\n", INT_MIN);
	le_pf = printf("PF (+030d) -> [%+030d]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (-+030.20d) -> [%-+030.20d]\n", 0);
	le_pf = printf("PF (-+030.20d) -> [%-+030.20d]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+d) -> [% +d]\n", 0);
	le_pf = printf("PF (+d) -> [% +d]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");


	// Un numero decimal sin signo (u)
	ft_printf("## Unsigned int.\n\n");
	le_ft_pf = ft_printf("FT (+030u) -> [%+030u]\n", INT_MAX);
	le_pf = printf("PF (+030u) -> [%+030u]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+030u) -> [%+030u]\n", INT_MAX/2);
	le_pf = printf("PF (+030u) -> [%+030u]\n",  INT_MAX/2);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+030.20u) -> [%+030.20u]\n", 0);
	le_pf = printf("PF (+030.20u) -> [%+030.20u]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (-+020.30u) -> [%-+020.30u]\n", 0);
	le_pf = printf("PF (-+020.30u) -> [%-+020.30u]\n",  0);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");


	// Un numero hexadecimal en minusculas (x)
	ft_printf("HEX number lowercase.\n\n");
	le_ft_pf = ft_printf("FT (-x) -> [%-x]\n", INT_MAX);
	le_pf = printf("PF (-x) -> [%-x]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (020x) -> [%020x]\n", INT_MIN);
	le_pf = printf("PF (020x) -> [%020x]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+030.20x) -> [%+030.20x]\n", 42);
	le_pf = printf("PF (+030.20x) -> [%+030.20x]\n",  42);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un numero hexadecimal en mayusculas (x)
	ft_printf("HEX number uppercase.\n\n");
	le_ft_pf = ft_printf("FT (-X) -> [%-X]\n", INT_MAX);
	le_pf = printf("PF (-X) -> [%-X]\n",  INT_MAX);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (020X) -> [%020X]\n", INT_MIN);
	le_pf = printf("PF (020X) -> [%020X]\n",  INT_MIN);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (+030.20X) -> [%+030.20X]\n", 42);
	le_pf = printf("PF (+030.20X) -> [%+030.20X]\n",  42);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");

	// Un puntero (p)
	ft_printf("## Pointer.\n\n");
	le_ft_pf = ft_printf("FT (p) -> [%p]\n", &s);
	le_pf = printf("PF (p) -> [%p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (-30.p) -> [%-30.p]\n", &s);
	le_pf = printf("PF (-30.p) -> [%-30.p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (-30.20p) -> [%-30.20p]\n", &s);
	le_pf = printf("PF (-30.20p) -> [%-30.20p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (30.20p) -> [%30.20p]\n", &s);
	le_pf = printf("PF (30.20p) -> [%30.20p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT (20.30p) -> [%20.30p]\n", &s);
	le_pf = printf("PF (20.30p) -> [%20.30p]\n", &s);
	ft_printf("Long FT -> %d\nLong PF -> %d\n\n", le_ft_pf, le_pf);
	le_ft_pf = ft_printf("FT -> [%p]\n", NULL);
	le_pf = printf("PF -> [%p]\n", NULL);
	ft_printf("Long FT -> %d\nLong PF -> %d\n", le_ft_pf, le_pf);
	ft_printf("/-----------------------------------------/\n\n");
}

