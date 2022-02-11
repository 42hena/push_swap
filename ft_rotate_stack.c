#include "push_swap.h"

void rotate_stack(t_stack *stack, int kind)
{
    stack->bottom = stack->bottom->next;
    stack->top = stack->top->next;
    if (kind == ASTACK)
        printf("ra\n");
    else if (kind == BSTACK)
        printf("rb\n");
}

void reverse_rotate_stack(t_stack *stack, int kind)
{
    stack->top = stack->top->prev;
    stack->bottom = stack->bottom->prev;
    if (kind == ASTACK)
        printf("rra\n");
    else if (kind == BSTACK)
        printf("rrb\n");
}

void rotatestack(t_stack *stack)
{
    stack->bottom = stack->bottom->next;
    stack->top = stack->top->next;
}

void rotate_togather(t_stack *a, t_stack *b)
{
    rotatestack(a);
    rotatestack(b);
    printf("rr\n");
}

void reverserotatestack(t_stack *stack)
{
    stack->top = stack->top->prev;
    stack->bottom = stack->bottom->prev;
}

void reverse_rotate_togather(t_stack *a, t_stack *b)
{
    // reverserotatestack(a);
    // reverserotatestack(b);
    printf("rrr\n");
}