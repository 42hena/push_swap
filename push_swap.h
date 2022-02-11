#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASTACK 0
#define BSTACK 1
#define INTMAX 2147483647
#define INTMIN -2147483648

typedef struct s_dllist {
	struct s_dllist *prev;
	struct s_dllist *next;
	int	value;
}				t_dllist;

typedef struct s_stack{
	t_dllist *top;
	t_dllist *bottom;
	int		size;
}				t_stack;

void		check_parameter(int argc, char **argv);
t_stack*	init_stack();
void		insert_stack(t_stack *stack, char *str);

void push_another_stack(t_stack *from, t_stack *to, int kind);

void swap_stack(t_stack *stack, int kind);
void swapstack(t_stack *stack);
void swap_togather(t_stack *a, t_stack *b);
void rotate_stack(t_stack *stack, int kind);
void reverse_rotate_stack(t_stack *stack, int kind);
void rotatestack(t_stack *stack);
void rotate_togather(t_stack *a, t_stack *b);
void reverserotatestack(t_stack *stack);
void reverse_rotate_togather(t_stack *a, t_stack *b);

void a_to_b(t_stack * a, t_stack * b, int r);
void b_to_a(t_stack * a, t_stack * b, int r);
void find_min_max(t_stack *tmp, int size, int pivot[2]);
void print(t_stack *tmp, int kind);
# endif
