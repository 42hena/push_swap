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

t_dllist* init_dllist(int num)
{
	t_dllist *tmp;
	
	tmp = (t_dllist *)malloc(sizeof(t_dllist));
	tmp->prev = tmp;
	tmp->next = tmp;
	tmp->value = num;
	return (tmp);
}

void		insert_stack(t_stack *stack, char *str)
{
	int num;

	num = get_number(str);
	if (stack->size == 0)
	{
		t_dllist *tmp = init_dllist(num);
		stack->top = tmp;
		stack->bottom = tmp;
		stack->size++;
	}
	else
	{
		t_dllist *iter = stack->top;
		int size = stack->size - 1;
		t_dllist *tmp = init_dllist(num);
		iter->prev = tmp;
		while (size--)
			iter = iter->next;
		iter->next = tmp;
		tmp->prev = iter;
		tmp->next = stack->top;
		stack->bottom = tmp;
		stack->size++;
	}
}

t_stack*	init_stack()
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (false);
	tmp->top = NULL;
	tmp->bottom = NULL;
	tmp->size = 0;
	return (tmp);
}