#include "push_swap.h"

static bool is_exist_duplicate(int *arr, int size)
{
    int i;
    int j;

    i = -1;
    while (++i < size)
    {
        j = i;
        while (++j < size)
        {
            if (arr[i] == arr[j])
                return (false);
        }
    }
    return (true);
}

static void create_array(t_stack *a, int **arr)
{
    int i;
    int size;
    t_dllist *list;

    size = a->size;
    *arr = (int *)malloc(sizeof(int) * size);
    list = a->top;
    i = -1;
    while (++i < size)
    {
        (*arr)[i] = list->value;
        list = list->next;
    }
}

void    check_duplicate(t_stack *a, t_stack *b)
{
    int     *arr;
    int     ret;
    int     size;

    size = a->size;
    create_array(a, &arr);
    ret = is_exist_duplicate(arr, size);
    free(arr);
    if (!ret)
        print_error("Error\nduplicate exist", a, b);
}