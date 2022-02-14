#include "push_swap.h"

static void init(t_stack *a, int arr[])
{
    t_dllist *tmp = a->top;
    int i;

    i = -1;
    while (++i < a->size)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
    }
}
int bubble(int sort[], int r)
{
    int tmp;
    for (int i = 0 ; i < r ; ++i)
    {
        for (int j = 0 ; j < r ; ++j)
        {
            if (sort[i] < sort[j])
            {
                tmp = sort[i];
                sort[i] = sort[j];
                sort[j] = tmp;
            }
        }
    }

    return sort[2];
}
int getmidvalue(int arr[], int r)
{
    int sort[5];

    for (int i = 0 ; i < r ; ++i)
        sort[i] = arr[i];
    return bubble(sort, r);
}

void as_five(t_stack *a, t_stack *b, int r)
{
    int arr[5];
    int mid;

    init(a, arr);
    
    mid = getmidvalue(arr, r);

    int size = r;
    while (size--)
    {
        if (a->top->value >= mid)
            rotate_stack(a, ASTACK);
        else
            push_another_stack(a, b, BSTACK);
    }
    a_to_b(a, b, 3);
    b_to_a(a, b, 2);
}

void as_four(t_stack *a, t_stack *b, int r)
{
    int arr[4];
    int mid;

    init(a, arr);
    mid = getmidvalue(arr, r);
    // printf("mid:%d\n", mid);
    int size = r;
    while (size--)
    {
        if (a->top->value >= mid)
            rotate_stack(a, ASTACK);
        else
            push_another_stack(a, b, BSTACK);
    }
    a_to_b(a, b, 2);
    b_to_a(a, b, 2);
}