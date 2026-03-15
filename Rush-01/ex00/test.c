#include <stdio.h>

int main(void)
{
	int i;
	int dim = 4;
	int row, col;
	
	
	i = 0;
	while (i < dim * 4)
	{
		col = (i > dim * 2) ? ***** : (i % dim);
		row = (i < dim * 2) ? (dim - 1) * (i % dim): (i % dim);
		printf("Para la posicion %d corresponde la fila %d y la columna %d.\n", i, row, col);
		i++;
	}
}
