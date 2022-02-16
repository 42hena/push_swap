#include "push_swap.h"

static void	bubble(int arr[], int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

bool	check_same(t_stack *a, int arr[])
{
	t_dllist	*list;
	int			size;
	int			i;

	size = a->size;
	list = a->top;
	i = -1;
	while (++i < size)
	{
		if (arr[i] != list->value)
			return (false);
		list = list->next;
	}
	return (true);
}

void	check_sort(t_stack *a, t_stack *b)
{
	int			size;
	int			*arr;
	int			i;
	t_dllist	*list;

	list = a->top;
	i = -1;
	size = a->size;
	arr = (int *)malloc(sizeof(int) * size);
	while (++i < size)
	{
		arr[i] = list->value;
		list = list->next;
	}
	bubble(arr, size);
	if (check_same(a, arr))
	{
		free(arr);
		print_error("", a, b);
	}
	free(arr);
}
