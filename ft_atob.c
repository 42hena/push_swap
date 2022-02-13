#include "push_swap.h"

//ra pb rb
static void init_command(int command[3])
{
    command[0] = 0;
    command[1] = 0;
    command[2] = 0;
}
//a스택 값
static void get_info(t_stack *a, t_stack *b, int c[3], int p[2])
{
    t_dllist *tmp;

    tmp = a->top;
    
    if (tmp->value >= p[0] && a->size != 1)
    {
        rotate_stack(a, ASTACK);
        c[0]++;
    }
    else
    {
        push_another_stack(a, b, BSTACK);
        c[1]++;
        if (b->top->value >= p[1] && b->size != 1)
        {
            rotate_stack(b, BSTACK);
            c[2]++;
        }
    }
    
}
//ra pb rb
static void reverse(t_stack * a, t_stack * b, int c[])
{
    int count;

    count = c[2];
    while (count--)
        reverse_rotate_togather(a, b);
    count = c[0] - c[2];
    while (count--)
        reverse_rotate_stack(a, ASTACK);
}
//ra vs rra

void a_to_b(t_stack * a, t_stack * b, int r)
{
    int command[3];
    int pivot[2];
    
    if (r <= 3)
    {
        a_under_three(r, a);
        return ;
    }
    init_command(command);
    find_min_max(a, r, pivot);
    
    while (r--)
        get_info(a, b, command, pivot);
    
    reverse(a, b, command);
    // print(a, ASTACK);
    // print(b, BSTACK);
    // printf("%d %d %d", command[0], command[1], command[2]);
    a_to_b(a, b, command[0]);//ra
    b_to_a(a, b, command[2]);//rb
    b_to_a(a, b, command[1] - command[2]);//pb - rb
}