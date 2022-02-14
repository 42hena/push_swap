#include <stdio.h>
#include "push_swap.h"

void print(t_stack *tmp, int kind)
{
	if (tmp->top == NULL){
		printf("no\n");
		return ;
	}
	int size = tmp->size;
	
	t_dllist *list = tmp->top;
	if (kind == ASTACK)
		printf("A STACK start\n");
	else
		printf("B STACK start\n");
	while (size--)
	{
		printf(" [%d]", list->value);
		list = list->next;
	}
	printf("\ncout end\n");
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	// printf("argv start\n");
	// for (int i = 0 ; i < argc ; ++i)
	// 	printf("index[%d]:%s\n", i, argv[i]);
	// printf("argv end\n\n");

	check_parameter(argc, argv);
	a = init_stack();
	b = init_stack();
	
	for (int i = 1 ; i < argc ; ++i)
		insert_stack(a, argv[i]);
	check_sort(a);
	
	// print(a, ASTACK);
	// print(b, BSTACK);
	printf("a_to_b test\n");
	a_to_b(a, b, a->size);
	print(a, ASTACK);
	print(b, BSTACK);
}