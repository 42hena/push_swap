/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:48:27 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 14:52:49 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack, int kind)
{
	stack->bottom = stack->bottom->next;
	stack->top = stack->top->next;
	if (kind == ASTACK)
		write(1, "ra\n", 3);
		// printf("ra\n");
	else if (kind == BSTACK)
		write(1, "rb\n", 3);
	// 	printf("rb\n");
	// print_stack(stack);
}

void	rotatestack(t_stack *stack)
{
	stack->bottom = stack->bottom->next;
	stack->top = stack->top->next;
}

void	rotate_togather(t_stack *a, t_stack *b)
{
	rotatestack(a);
	rotatestack(b);
	write(1, "rr\n", 3);
	// printf("rr\n");
	// print_stack(a);
	// print_stack(b);
}
