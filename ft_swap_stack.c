/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:37:25 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 14:43:21 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap_kind(int kind)
{
	if (kind == ASTACK)
		write(1, "sa\n", 3);
	else if (kind == BSTACK)
		write(1, "sb\n", 3);
}

void	swap_stack(t_stack *stack, int kind)
{
	t_dllist	*now;
	t_dllist	*prev;
	t_dllist	*next;

	if (stack->size == 2)
	{
		stack->top = stack->top->next;
		stack->bottom = stack->top->next;
	}
	else
	{
		now = stack->top;
		prev = now->prev;
		next = now->next;
		now->next = next->next;
		next->prev = prev;
		next->next->prev = now;
		next->next = now;
		now->prev = next;
		prev->next = next;
		stack->top = next;
	}
	print_swap_kind(kind);
}

void	swapstack(t_stack *stack)
{
	t_dllist	*now;
	t_dllist	*prev;
	t_dllist	*next;

	if (stack->size == 2)
	{
		stack->top = stack->top->next;
		stack->bottom = stack->top->next;
	}
	else
	{
		now = stack->top;
		prev = now->prev;
		next = now->next;
		now->next = next->next;
		next->prev = prev;
		next->next->prev = now;
		next->next = now;
		now->prev = next;
		prev->next = next;
		stack->top = next;
	}
}

void	swap_togather(t_stack *a, t_stack *b)
{
	swapstack(a);
	swapstack(b);
	write(1, "ss\n", 3);
}
