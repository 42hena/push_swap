#include <stdio.h>
#include "push_swap.h"


void swap_stack(t_stack *stack, int kind)
{
    if (stack->size == 2)
    {
        stack->top = stack->top->next;
        stack->bottom = stack->top->next;
    }
    else
    {
        t_dllist *now = stack->top;
        t_dllist *prev = now->prev;
        t_dllist *next = now->next;
        now->next = next->next;
        next->prev = prev;
        next->next->prev = now;
        next->next = now;
        now->prev = next;
        prev->next = next;       
        stack->top = next;
    }
    if (kind == ASTACK)
        printf("sa\n");
    else if (kind == BSTACK)
        printf("sb\n");
}

void swapstack(t_stack *stack)
{
    if (stack->size == 2)
    {
        stack->top = stack->top->next;
        stack->bottom = stack->top->next;
    }
    else
    {
        t_dllist *now = stack->top;
        t_dllist *prev = now->prev;
        t_dllist *next = now->next;
        now->next = next->next;
        next->prev = prev;
        next->next->prev = now;
        next->next = now;
        now->prev = next;
        prev->next = next;       
        stack->top = next;
    }
}

void swap_togather(t_stack *a, t_stack *b)
{
    swapstack(a);
    swapstack(b);
    printf("ss\n");
}
