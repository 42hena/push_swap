#include "push_swap.h"

void handle_from(t_stack *from)
{
    t_dllist * iter_from;
    if (from->size == 1) // 0개 될 예정
    {
        iter_from = from->top; //선언받기
        from->top = NULL;
        from->bottom = NULL;
    }
    else
    {
        iter_from = from->top;
        iter_from->next->prev = iter_from->prev;
        iter_from->prev->next = iter_from->next;
        from->top = iter_from->next;
    }
    from->size--;
}
void handle_to(t_stack *to)
{
    t_dllist * iter_from;
    t_dllist * iter_to;

    if (to->size == 0)
    {
        to->top = iter_from;
        to->bottom = iter_from;
        iter_from->prev = iter_from;
        iter_from->next = iter_from;
    }
    else{
        to->top = iter_from;
        iter_from->prev = iter_to->prev;
        iter_from->next = iter_to;
    }
    to->size++;
}
void push_another_stack(t_stack *from, t_stack *to)
{
    handle_from(from);
    handle_to(to);
}