#include "push_swap.h"
void find_min_max(t_stack *tmp, int size, int pivot[2])
{
    int maxValue;
    int minValue;
    t_dllist *list;

    maxValue = INTMIN;
    minValue = INTMAX;
    list = tmp->top;
    while (size--)
    {
        if (minValue > list->value)
            minValue = list->value;
        if (maxValue < list->value)
            maxValue = list->value;
        list = list->next;
    }
    pivot[0] = (maxValue + minValue) / 2;
    pivot[1] = (pivot[0] + minValue) / 2;
}

int ft_max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int ft_min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}