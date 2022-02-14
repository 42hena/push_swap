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
	
	check_sort(a);
	// a_to_b(a, b, a->size);
}