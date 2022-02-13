#include "push_swap.h"

static void init_command(int command[3])
{
    command[0] = 0;
    command[1] = 0;
    command[2] = 0;
}
//b스택 값
static void get_info(t_stack *a, t_stack *b, int c[3], int p[2])
{
    t_dllist *tmp;

    tmp = b->top;
    if (tmp->value < p[1] && b->size != 1)
    {
        rotate_stack(b, BSTACK);
        c[0]++;
    }
    else
    {
        push_another_stack(b, a, ASTACK);
        c[1]++;
        if (tmp->value < p[0] && a->size != 1)
        {
            rotate_stack(a, ASTACK);
            c[2]++;
        }
    }
}

static void reverse(t_stack * a, t_stack * b, int c[])
{
    int count;

    count = c[2];
    while (count--)
        reverse_rotate_togather(a, b);
    count = c[0] - c[2];
    while (count--)
        reverse_rotate_stack(b, BSTACK);
}

//rb pa ra
void b_to_a(t_stack * a, t_stack * b, int r)
{
    int command[3];
    int pivot[2];

    if (r <= 3)
    {
        b_under_three(r, a, b);
        return ;
    }
    init_command(command);
    find_min_max(b, r, pivot);
    while (r--)
        get_info(a, b, command, pivot);
    a_to_b(a, b, command[1] - command[2]);// pa - ra;
    reverse(a, b, command);
    a_to_b(a, b, command[2]); // ra
    b_to_a(a, b, command[0]); // rb
}