#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void ft_eliminate_list(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*previous;
	
	previous = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		if ((*cmp)(data, current->data))
		{
			if (previous == NULL)
			{
				*begin_list = current->next;
				previous = NULL;
				//free(current->data);
				free(current);
				current = *begin_list;
			}
			else
			{
				previous->next = current->next;
				//free(current->data);
				free(current);
				current = previous->next;
			}
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}




int compare(void *data1, void *data2)
{
	return (data1 == data2);
}


void ft_print_lista(t_list **begin_list)
{
	t_list *current;
	
	current = *begin_list;
	while (current != NULL)
	{
		printf("El valor del nodo es: %s\n", (char *) current->data);
		current = current->next;
	}
}

#include <stdio.h>

int main()
{
	t_list	*lista;
	char	*h = "Hola";
	char	*m = "Mundo";
	char	*f = "Fantastico";
	
	lista = malloc(sizeof(t_list));
	lista->data = NULL;
	lista->next = malloc(sizeof(t_list));
	lista->next->data = NULL;
	lista->next->next = malloc(sizeof(t_list));
	lista->next->next-> data = h;	
	lista->next->next->next = malloc(sizeof(t_list));
	lista->next->next->next->data = m;	
	lista->next->next->next->next = malloc(sizeof(t_list));
	lista->next->next->next->next->data = f;
	lista->next->next->next->next->next = NULL;
	
	ft_print_lista(&lista);
	printf("Paso 1: eliminamos %s.\nLa lista queda:\n", NULL);	
	ft_eliminate_list(&lista, NULL, &compare);
	ft_print_lista(&lista);
	printf("Paso 2: eliminamos %s.\nLa lista queda:\n", NULL);	
	ft_eliminate_list(&lista, NULL, &compare);
	ft_print_lista(&lista);
	printf("Paso 3: eliminamos %s.\nLa lista queda:\n", m);	
	ft_eliminate_list(&lista, m, &compare);
	ft_print_lista(&lista);
	printf("Paso 4: eliminamos %s.\nLa lista queda:\n", f);	
	ft_eliminate_list(&lista, f, &compare);
	ft_print_lista(&lista);
	printf("Paso 5: eliminamos %s.\nLa lista queda:\n", h);	
	ft_eliminate_list(&lista, h, &compare);
	ft_print_lista(&lista);

	return 1;
}

