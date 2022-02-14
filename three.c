#include "push_swap.h"

void init_arr(int arr[], int r, t_dllist *tmp)
{
    int i;

    i = 0;
    while (r--)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
        ++i;
    }
}
//오름차순
void a_two(t_stack *a)
{
    int arr[2];
    t_dllist *tmp;
    
    tmp = a->top;
    arr[0] = tmp->value ;
    arr[1] = tmp->next->value;
    if (arr[0] > arr[1])
        swap_stack(a, ASTACK);
    return ;
}
void as_three(t_stack *a, int r)
{
    int arr[3];

    init_arr(arr, r, a->top);
    //1 2 3 생략
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    // if (arr[0] < arr[1] && arr[1] < arr[2])
    //     printf("1 < 2 < 3\n");
    if (arr[0] < arr[2] && arr[2] < arr[1])         //1 3 2
    {
        swap_stack(a, ASTACK);                      //3 1 2
        rotate_stack(a, ASTACK);                    //1 2 3
    }
    else if (arr[1] < arr[0] && arr[0] < arr[2])    //2 1 3
        swap_stack(a, ASTACK);                      //1 2 3
    else if (arr[2] < arr[0] && arr[0] < arr[1])    //2 3 1
        reverse_rotate_stack(a, ASTACK);            //1 2 3
    else if (arr[1] < arr[2] && arr[2] < arr[0])    //3 1 2
        rotate_stack(a, ASTACK);                    //1 2 3
    else if (arr[2] < arr[1] && arr[1] < arr[0])    //3 2 1
    {
        rotate_stack(a, ASTACK);                    //2 1 3
        swap_stack(a, ASTACK);                      //1 2 3
    }
}

void ab_three(t_stack *a, int r)
{
    int arr[3];

    init_arr(arr, r, a->top);
    // 1 2 3 생략
    // if (arr[0] < arr[1] && arr[1] < arr[2])
    //     printf("1 < 2 < 3\n");
    if (arr[0] < arr[2] && arr[2] < arr[1])         //1 3 2 ...
    {
        rotate_stack(a, ASTACK);                    //3 2 ... 1
        swap_stack(a, ASTACK);                      //2 3 ... 1
        reverse_rotate_stack(a, ASTACK);            //1 2 3 ...
    }
    else if (arr[1] < arr[0] && arr[0] < arr[2])    //2 1 3 ...
        swap_stack(a, ASTACK);                      //1 2 3 ...
    else if (arr[2] < arr[0] && arr[0] < arr[1])    //2 3 1 ...
    {
        rotate_stack(a, ASTACK);                    //3 1 ... 2
        swap_stack(a, ASTACK);                      //1 3 ... 2
        reverse_rotate_stack(a, ASTACK);            //2 1 3 ...
        swap_stack(a, ASTACK);                      //1 2 3 ...
    }
    else if (arr[1] < arr[2] && arr[2] < arr[0])    //3 1 2 ...
    {
        swap_stack(a, ASTACK);                      //1 3 2 ...
        rotate_stack(a, ASTACK);                    //3 2 ... 1
        swap_stack(a, ASTACK);                      //2 3 ... 1
        reverse_rotate_stack(a, ASTACK);            //1 2 3 ...
    }
    else if (arr[2] < arr[1] && arr[1] < arr[0])    //3 2 1 ...
    {
        swap_stack(a, ASTACK);                      //2 3 1 ...
        rotate_stack(a, ASTACK);                    //3 1 ... 2
        swap_stack(a, ASTACK);                      //1 3 ... 2
        reverse_rotate_stack(a, ASTACK);            //2 1 3 ...
        swap_stack(a, ASTACK);                      //1 2 3 ...
    }
}


void a_under_five(t_stack *a, t_stack *b, int r)
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
//------------------------------------------------

void b_two(t_stack *b)
{
    int arr[2];
    t_dllist *tmp;
    
    tmp = b->top;
    arr[0] = tmp->value ;
    arr[1] = tmp->next->value;
    if (arr[0] < arr[1])                            //1 2
        swap_stack(b, BSTACK);                      //2 1
}
void bs_three(t_stack *b, int r)
{
    int arr[3];

    init_arr(arr, r, b->top);
    if (arr[0] < arr[1] && arr[1] < arr[2])         //1 2 3 
    {
        rotate_stack(b, BSTACK);                    //2 3 1
        rotate_stack(b, BSTACK);                    //3 2 1
    }
    else if (arr[0] < arr[2] && arr[2] < arr[1])    //1 3 2
        rotate_stack(b, BSTACK);                    //3 2 1
    else if (arr[1] < arr[0] && arr[0] < arr[2])    //2 1 3
        reverse_rotate_stack(b, BSTACK);            //3 2 1
    else if (arr[2] < arr[0] && arr[0] < arr[1])    //2 3 1
        swap_stack(b, BSTACK);                      //3 2 1
    else if (arr[1] < arr[2] && arr[2] < arr[0])    //3 1 2
    {
        reverse_rotate_stack(b, BSTACK);            //2 3 1
        swap_stack(b, BSTACK);                      //3 2 1
    }
    // else if (arr[2] < arr[1] && arr[1] < arr[0])
    //     printf("3 > 2 > 1\n");
}

/*
내림 차순
*/
void bb_three(t_stack *b, int r)
{
    int arr[3];

    init_arr(arr, r, b->top);
    if (arr[0] < arr[1] && arr[1] < arr[2])         //1 2 3 ...
    {
        swap_stack(b, BSTACK);                      //2 1 3 ...
        rotate_stack(b, BSTACK);                    //2 1 ... 3
        reverse_rotate_stack(b, BSTACK);            //3 2 1 ...
    }
    else if (arr[0] < arr[2] && arr[2] < arr[1])    //1 3 2 ...
    {
        swap_stack(b, BSTACK);                      //3 1 2 ...
        rotate_stack(b, BSTACK);                    //1 2 ... 3
        swap_stack(b, BSTACK);                      //2 1 ... 3
        reverse_rotate_stack(b, BSTACK);            //3 2 1 ...
    }
    else if (arr[1] < arr[0] && arr[0] < arr[2])    //2 1 3 ...
    {
        rotate_stack(b, BSTACK);                    //1 3 ... 2
        swap_stack(b, BSTACK);                      //3 1 ... 2
        reverse_rotate_stack(b, BSTACK);            //2 3 1 ...
        swap_stack(b, BSTACK);                      //3 2 1 ...
    }
    else if (arr[2] < arr[0] && arr[0] < arr[1])    //2 3 1 ...
        swap_stack(b, BSTACK);                      //3 2 1 ...
    else if (arr[1] < arr[2] && arr[2] < arr[0])    //3 1 2 ...
    {
        rotate_stack(b, BSTACK);                    //1 2 ... 3
        swap_stack(b, BSTACK);                      //2 1 ... 3
        reverse_rotate_stack(b, BSTACK);            //3 2 1 ...
    }
    // else if (arr[2] < arr[1] && arr[1] < arr[0])
    //     printf("3 > 2 > 1\n");
    //3 2 1 생략
}

void b_under_three(t_stack *a, t_stack *b, int r)
{
    int size;

    size = b->size;
    if (r <= 0)
        return ;
    if (r == 2)
        b_two(b);
    else
    {
        if (size > 3)
            bb_three(b, 3);
        else
            bs_three(b, 3); 
    }
    for (int i = 0 ; i < r ; ++i)
        push_another_stack(b, a, ASTACK);
}