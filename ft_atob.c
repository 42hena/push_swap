#include "push_swap.h"

static void	init_command(int command[3])
{
	command[0] = 0;
	command[1] = 0;
	command[2] = 0;
}

static void	get_info(t_stack *a, t_stack *b, int c[3], int p[2])
{
	t_dllist	*tmp;

	tmp = a->top;
	if (tmp->value >= p[0])
	{
		rotate_stack(a, ASTACK);
		c[0]++;
	}
	else
	{
		push_another_stack(a, b, BSTACK);
		c[1]++;
		if (b->top->value >= p[1])
		{
			rotate_stack(b, BSTACK);
			c[2]++;
		}
	}
}

static void	reverse(t_stack *a, t_stack *b, int c[])
{
	int	i;

	i = 0;
	printf("%d %d", c[0], c[2]);
	while (i < c[0] && i < c[2])
	{
		reverse_rotate_togather(a, b);
		++i;
	}
	while (i < c[0])
	{
		reverse_rotate_stack(a, ASTACK);
		++i;
	}
	while (i < c[2])
	{
		reverse_rotate_stack(b, BSTACK);
		++i;
	}
}

void	a_to_b(t_stack *a, t_stack *b, int r)
{
	int	command[3];
	int	pivot[2];

	printf("in a r:%d\n", r);
	print_stack(a);
	print_stack(b);
	if (r <= 3)
	{
		a_under_three(a, b, r);
		return ;
	}
	init_command(command);
	find_min_max(a, r, pivot);
	printf("p1:%d p2:%d\n", pivot[0], pivot[1]);
	while (r--)
		get_info(a, b, command, pivot);
	reverse(a, b, command);
	a_to_b(a, b, command[0]);//ra
	b_to_a(a, b, command[2]);//rb
	b_to_a(a, b, command[1] - command[2]);//pb - rb
}
