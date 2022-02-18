#include "push_swap.h"

void    ab_five(t_stack *a, t_stack *b, int r)
{
    int arr[5];
    int mid;
    int com[2] = {0, 0};
    int i = -1;
    t_dllist *tmp;

    init(a, arr, r);
    mid = getmidvalue(arr, r);

    tmp = a->top;
    while (++i < r)
    {
        if (tmp->value >= mid)
            com[0]++; //ra
        else
            com[1]++; //pb
        tmp = tmp->next;
    }
    i = -1;
    while (++i < r)
    {
        if (a->top->value >= mid && com[1])
        {
            rotate_stack(a, ASTACK);
            com[0]--;
        }
        else if (a->top->value < mid)
        {
            push_another_stack(a, b, BSTACK);
            com[1]--;
        }
    }
    for (int i = 0  ; i < r - 2 - com[0] ; ++i)
        reverse_rotate_stack(a, ASTACK);
    a_to_b(a, b, r - 2);
    b_to_a(a, b, 2);
}
