#include "push_swap.h"

t_dllist	*handle_from(t_stack *from)
{
	t_dllist	*iter_from;

	if (from->size == 1)
	{
		iter_from = from->top;
		from->top = NULL;
		from->bottom = NULL;
	}
	else
	{
		iter_from = from->top;
		iter_from->next->prev = iter_from->prev;
		iter_from->prev->next = iter_from->next;
		from->top = iter_from->next;
	}
	from->size--;
	return (iter_from);
}

void	handle_to(t_dllist *iter_from, t_stack *to)
{
	t_dllist	*iter_to;

	iter_to = to->top;
	if (to->size == 0)
	{
		iter_from->prev = iter_from;
		iter_from->next = iter_from;
		to->top = iter_from;
		to->bottom = iter_from;
	}
	else
	{
		iter_from->prev = iter_to->prev;
		iter_from->next = iter_to;
		iter_to->prev = iter_from;
		iter_from->prev->next = iter_from;
		to->top = iter_from;
	}
	to->size++;
}

void	push_another_stack(t_stack *from, t_stack *to, int kind)
{
	t_dllist	*iter_from;

	iter_from = handle_from(from);
	handle_to(iter_from, to);
	if (kind == ASTACK)
		write(1, "pa\n", 3);
	else if (kind == BSTACK)
		write(1, "pb\n", 3);
}
