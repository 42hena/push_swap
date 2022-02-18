/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:40:25 by hena              #+#    #+#             */
/*   Updated: 2022/02/18 17:49:07 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define ASTACK 0
# define BSTACK 1
# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_dllist {
	struct s_dllist	*prev;
	struct s_dllist	*next;
	long long		value;
}				t_dllist;

typedef struct s_stack{
	t_dllist	*top;
	t_dllist	*bottom;
	int			size;
}				t_stack;

typedef struct s_info{
	int			command[3];
	int			pivot[2];
	int			r;
}				t_info;

t_stack		*init_stack(void);
bool		check_parameter(int argc, char **argv, t_stack *a);
bool		check_argc(int argc);
bool		check_argv(int argc, char **argv, t_stack *a);
void		insert_stack(t_stack *stack, long long sum);
void		print_error(const char *s, t_stack *a, t_stack *b);
void		is_int_range(t_stack *a, t_stack *b);
void		check_duplicate(t_stack *a, t_stack *b);
void		check_sort(t_stack *a, t_stack *b);

void		push_another_stack(t_stack *from, t_stack *to, int kind);

void		swap_stack(t_stack *stack, int kind);
void		swapstack(t_stack *stack);
void		swap_togather(t_stack *a, t_stack *b);
void		rotate_stack(t_stack *stack, int kind);
void		reverse_rotate_stack(t_stack *stack, int kind);
void		rotatestack(t_stack *stack);
void		rotate_togather(t_stack *a, t_stack *b);
void		reverserotatestack(t_stack *stack);
void		reverse_rotate_togather(t_stack *a, t_stack *b);
void		a_to_b(t_stack *a, t_stack *b, int r);
void		b_to_a(t_stack *a, t_stack *b, int r);
void		find_pivot(t_stack *tmp, t_info *info);
void		print(t_stack *tmp, int kind);

void		a_under_three(t_stack *a, t_stack *b, int r);
void		b_under_three(t_stack *a, t_stack *b, int r);
void		a_under_five(t_stack *a, t_stack *b, int r);
void		as_five(t_stack *a, t_stack *b, int r);
void		as_four(t_stack *a, t_stack *b, int r);
void		a_two(t_stack *a);
void		as_three(t_stack *a, int r);
void		ab_three(t_stack *a, int r);
void		ab_five(t_stack *a, t_stack *b, int r);
void		ab_four(t_stack *a, t_stack *b, int r);
void		bb_five(t_stack *a, t_stack *b, int r);
void		bb_four(t_stack *a, t_stack *b, int r);

void		a_min_max_mid(t_stack *a);
void		a_mid_min_max(t_stack *a);
void		a_mid_max_min(t_stack *a);
void		a_max_min_mid(t_stack *a);
void		a_max_mid_min(t_stack *a);

void		b_min_mid_max(t_stack *b);
void		b_min_max_mid(t_stack *b);
void		b_mid_min_max(t_stack *b);
void		b_mid_max_min(t_stack *b);
void		b_max_min_mid(t_stack *b);
void		print_stack(t_stack *tmp);
int			getmidvalue(int arr[], int r);
void		init(t_stack *a, int arr[], int r);
#endif
