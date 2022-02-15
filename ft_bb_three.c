#include "push_swap.h"

void	b_min_mid_max(t_stack *b)
{
	swap_stack(b, BSTACK);
	rotate_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
}

void	b_min_max_mid(t_stack *b)
{
	swap_stack(b, BSTACK);
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
}

void	b_mid_min_max(t_stack *b)
{	
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
}

void	b_mid_max_min(t_stack *b)
{
	swap_stack(b, BSTACK);
}

void	b_max_min_mid(t_stack *b)
{
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
}
