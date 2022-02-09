#include "push_swap.h"

void rotate_stack(t_stack *stack)
{
    stack->bottom = stack->bottom->next;
    stack->top = stack->top->next;
}

void reverse_rotate_stack(t_stack *stack)
{
    stack->top = stack->top->prev;
    stack->bottom = stack->bottom->prev;
}

void rotate_togather(t_stack *a, t_stack *b)
{
    rotate_stack(a);
    rotate_stack(b);
}

void reverse_rotate_togather(t_stack *a, t_stack *b)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
}