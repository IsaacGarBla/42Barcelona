#include <stdio.h>

int main(void)
{
	int i;
	int dim = 5;
	int row, col;
	
	
	i = 0;
	while (i < dim * 4)
	{
		if (i <= (2 * dim -1))
		{
			col = i % dim;
			row  = (i / dim) * (dim -1);
	 	}
		else
		{
			col = (i / (dim * 3)) * (dim -1);
			row = i % dim;
		} 
		printf("Para la posicion %d corresponde la fila %d y la columna %d.\n", i, row, col);
		i++;
	}
}