#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	printf("argv start\n");
	for (int i = 0 ; i < argc ; ++i)
		printf("index[%d]:%s\n", i, argv[i]);
	printf("argv end\n\n");

	check_parameter(argc, argv);
	a = init_stack();

	b = init_stack();

	printf("%p %p\n", a, b);

	
	for (int i = argc - 1 ; i > 0 ; --i)
	{
		printf("insert:%s\n", argv[i]);
		insert_stack(a, argv[i]);
	}
	push_another_stack(a, b);
	int size = a->size;
	printf("size:%d\n", size);	
	t_dllist *tmp = a->top;
	printf("cout << a\n");
	while (size--)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	
	printf("\ncout << b\n");
	size = b->size;
	printf("size:%d\n", size);	
	tmp = b->top;
	while (size--)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	push_another_stack(b, a);
	size = a->size;
	printf("size:%d\n", size);	
	tmp = a->top;
	printf("cout << a\n");
	while (size--)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	
	printf("\ncout << b\n");
	size = b->size;
	printf("size:%d\n", size);	
	tmp = b->top;
	while (size--)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
}