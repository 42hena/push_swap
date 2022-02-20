/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:48:27 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:20:48 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack, int kind)
{
	stack->bottom = stack->bottom->next;
	stack->top = stack->top->next;
	if (kind == ASTACK)
		write(1, "ra\n", 3);
	else if (kind == BSTACK)
		write(1, "rb\n", 3);
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
}
