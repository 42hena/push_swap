#include "push_swap.h"

void    print_stack(t_stack *tmp)
{
    int size;
    t_dllist *list;

    size = tmp->size;
    printf("size:[%d]\n", size);
    list = tmp->top;
    while (size--)
    {
        printf("[%d]", (int)list->value);
        list = list->next;
    }
    printf("\n\n");
}