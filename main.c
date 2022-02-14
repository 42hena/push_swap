#include "push_swap.h"

int	main(int argc, char **argv)
{
	int i = 0;
	t_stack	*a;
	t_stack	*b;
	char **param;

	a = init_stack();
	b = init_stack();
	check_parameter(argc, argv, a);
	for (int i = 1 ; i < argc ; ++i)
		printf("%s\n", argv[i]);
	t_dllist *tmp;
	tmp = a->top;
	printf("%p", tmp);
	printf("tq");
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	/*
	for (int i = 1 ; i < argc ; ++i)
		insert_stack(a, argv[i]);
	check_sort(a);
	a_to_b(a, b, a->size);*/
}
