#include "push_swap.h"

int	get_number(char *str)
{
	int sum;

	sum = 0;
	while (*str)
	{
		sum = sum * 10 + *str -'0';
		str++;
	}
	return (sum);
}

t_dllist* init_dllist()
{
	printf("in");
	t_dllist *tmp = (t_dllist *)malloc(sizeof(t_dllist));
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->value = 0;
	return (tmp);
}

void		insert_stack(t_stack *stack, char *str)
{
	int num;

	num = get_number(str);

	printf("size:%d\n", stack->size);
	printf("num:%d\n", num);

	if (stack->size == 0)
	{
		printf("%d", stack->size);
		t_dllist *tmp = init_dllist();
		printf("hio");
		stack->top = tmp;
		stack->bottom = tmp;
		stack->size++;
	}
	
	else
	{
		while (stack->top)
		{
			stack->top = stack->top->next;
		}
		t_dllist *tmp = init_dllist();
		stack->top->next = tmp;
		tmp->prev = stack->top;
	}
}

t_stack*	init_stack()
{
	t_stack *tmp;

	tmp = NULL;
	printf("%p\n", tmp);
	tmp = (t_stack *)malloc(sizeof(t_stack));
	printf("%p\n", tmp);
	if (tmp == NULL)
		return (false);
	tmp->top = NULL;
	tmp->bottom = NULL;
	tmp->size = 0;
	return (tmp);
}
