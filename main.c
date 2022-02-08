#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	printf("argv start\n");
	for (int i = 0 ; i < argc ; ++i)
		printf("index[%d]:%s\n", i, argv[i]);
	printf("argv end\n");
	check_parameter(argc, argv);
	a = init_stack();
	printf("a:%p\n", a);
	b = init_stack();
	printf("b:%p\n", b);


	
	//printf("%p %p %d\n", a->top, a->bottom, a->size);
	//printf("%p %p %d\n", b->top, b->bottom, b->size);
	printf("%p %p\n", a, b);

	
	for (int i = argc - 1 ; i > 0 ; --i)
	{
		printf("%s\n", argv[i]);
		insert_stack(a, argv[i]);
	}
	t_stack *tmp = a;
	while (tmp->top)
	{
		printf("%d ", tmp->top->value);
		tmp->top = tmp->top->next;
	}
}
