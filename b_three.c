#include "push_swap.h"

static void	init_arr(int arr[], int r, t_dllist *tmp)
{
	int	i;

	i = 0;
	while (r--)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
}

static void	b_two(t_stack *b)
{
	int			arr[2];
	t_dllist	*tmp;

	tmp = b->top;
	arr[0] = tmp->value ;
	arr[1] = tmp->next->value;
	if (arr[0] < arr[1])
		swap_stack(b, BSTACK);
}

void	bs_three(t_stack *b, int r)
{
	int	arr[3];

	init_arr(arr, r, b->top);
	if (arr[0] < arr[1] && arr[1] < arr[2])
	{
		rotate_stack(b, BSTACK);
		rotate_stack(b, BSTACK);
	}
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		rotate_stack(b, BSTACK);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		reverse_rotate_stack(b, BSTACK);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		swap_stack(b, BSTACK);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
	{
		reverse_rotate_stack(b, BSTACK);
		swap_stack(b, BSTACK);
	}
}

void	bb_three(t_stack *b, int r)
{
	int	arr[3];

	init_arr(arr, r, b->top);
	if (arr[0] < arr[1] && arr[1] < arr[2])
		b_min_mid_max(b);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
		b_min_max_mid(b);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		b_mid_min_max(b);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		b_mid_max_min(b);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		b_max_min_mid(b);
}

void	b_under_three(t_stack *a, t_stack *b, int r)
{
	int	size;
	int	i;

	size = b->size;
	if (r <= 0)
		return ;
	if (r == 2)
		b_two(b);
	else
	{
		if (size > 3)
			bb_three(b, 3);
		else
			bs_three(b, 3);
	}
	i = -1;
	while (++i < r)
		push_another_stack(b, a, ASTACK);
}
