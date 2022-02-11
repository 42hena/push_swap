#include "push_swap.h"

/*void b_onesort(t_stack *a, t_stack *b)
{
    push_another_stack(b, a);
}

void a_twosort(t_stack *s, int r)
{
    if (s->top->value > s->top->next->value)
        swap_stack(s);
}

void b_twosort(t_stack *s, int r)
{
    if (s->top->value < s->top->next->value)
        swap_stack(s);
}


void threesort(t_stack *s, int m, int M)
{
    if (m == 0 && M == 2)
        return ;
    else if (m == 0 && M == 1)
    {
        swap_stack(s);
        rotate_stack(s, ASTACK);
    }
    else if (m == 1 && M == 2)
        swap_stack(s);
    else if (m == 2 && M == 1)
        reverse_rotate_stack(s);
    else if (m == 1 && M == 0)
        rotate_stack(s);
    else if (m == 2 && M == 0)
    {
        reverse_rotate_stack(s);
        reverse_rotate_stack(s);
    }
}

void find_pos(t_stack *s, int r, int m, int M)
{
    int i;
    int mindex;
    int Mindex;
    t_dllist *list;
    list = s->top;
    i = -1;
    while (++i < r)
    {
        if (m == list->value)
            mindex = list->value;
        if (M == list->value)
            Mindex = list->value;
        list = list->next;
    }
    threesort(s, mindex, Mindex);
}

void athreesort(t_stack *s, int r)
{
    int min_value = INTMAX;
    int max_value = INTMIN;
    int i;

    t_dllist *list;
    list = s->top;
    i = -1;
    while (++i < r)
    {
        if (min_value > list->value)
            min_value = list->value;
        if (max_value < list->value)
            max_value = list->value;
        list = list->next;
    }
    find_pos(s, r, min_value, max_value);
}*/