#include "push_swap.h"

void    a_under_five(t_stack *a, t_stack *b, int r)
{
    int size;

    size = a->size;
    if (r <= 1)
        return ;
    else if (r == 2)
        a_two(a);
    else if (r == 3)
    {
        if (size > 3)
            ab_three(a, 3);
        else
            as_three(a, 3);
    }
    else if (r == 4)
        as_four(a, b, r);
    else
        as_five(a, b, r);
}
