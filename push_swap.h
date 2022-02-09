#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



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

void push_another_stack(t_stack *from, t_stack *to);

void swap_stack(t_stack *stack);
void swap_togather(t_stack *a, t_stack *b);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);
void rotate_togather(t_stack *a, t_stack *b);
void reverse_rotate_togather(t_stack *a, t_stack *b);
# endif
