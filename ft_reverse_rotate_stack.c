/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:53:07 by hena              #+#    #+#             */
/*   Updated: 2022/02/17 19:39:58 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack, int kind)
{
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
	if (kind == ASTACK)
		//write(1, "rra\n", 4);
		 printf("rra\n");
	else if (kind == BSTACK)
		//write(1, "rrb\n", 4);
		 printf("rrb\n");
	// print_stack(stack);
}

void	reverserotatestack(t_stack *stack)
{
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
}

void	reverse_rotate_togather(t_stack *a, t_stack *b)
{
	reverserotatestack(a);
	reverserotatestack(b);
	printf("rrr\n");
	// printf("A STACK\n");
	// print_stack(a);
	// printf("B STACK\n");
	// print_stack(b);
	//write(1, "rrr\n", 4);
}
