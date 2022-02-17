#include "push_swap.h"

static void	init(t_stack *a, int arr[], int r)
{
	int			i;
	t_dllist	*tmp;

	tmp = a->top;
	i = -1;
	while (++i < r)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
}

static int	bubble(int sort[], int r)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	while (++i < r)
	{
		j = i;
		while (++j < r)
		{
			if (sort[i] > sort[j])
			{
				tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = tmp;
			}
		}
	}
	return (sort[2]);
}

static int	getmidvalue(int arr[], int r)
{
	int	sort[5];
	int	i;

	i = -1;
	while (++i < r)
		sort[i] = arr[i];
	return (bubble(sort, r));
}

void    bb_five(t_stack *a, t_stack *b, int r)
{
    int arr[5];
    int mid;
    int size;

    init(b, arr, r);
    mid = getmidvalue(arr, r);
    size = r;
    while (size--)
    {
        if (b->top->value >= mid)
            rotate_stack(a, ASTACK);
        else
            push_another_stack(a, b, BSTACK);
    }
    a_to_b(a, b, 3);
    b_to_a(a, b, 2);
}

void    bb_four(t_stack *a, t_stack *b, int r)
{
    int arr[4];
    int mid;
    int size;

    init(b, arr, r);
    mid = getmidvalue(arr, r);
    size = r;
    while (size--)
    {
        if (b->top->value >= mid)
            rotate_stack(b, BSTACK);
        else
            push_another_stack(b, a, ASTACK);
    }
    a_to_b(a, b, 2);
    b_to_a(a, b, 2);
}
