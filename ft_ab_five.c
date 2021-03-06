/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ab_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:21:21 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 14:40:16 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_com(int com[])
{
	com[0] = 0;
	com[1] = 0;
}

static void	get_com(t_stack *a, int com[], int r, int mid)
{
	int			i;
	t_dllist	*tmp;

	i = -1;
	tmp = a->top;
	while (++i < r)
	{
		if (tmp->value >= mid)
			com[0]++;
		else
			com[1]++;
		tmp = tmp->next;
	}
}

static void	restore_stack(t_stack *a, int r)
{
	int	i;

	i = -1;
	while (++i < r)
		reverse_rotate_stack(a, ASTACK);
}

void	ab_five(t_stack *a, t_stack *b, int r)
{
	int	arr[5];
	int	mid;
	int	com[2];
	int	i;

	init(a, arr, r);
	mid = getmidvalue(arr, r);
	get_com(a, com, r, mid);
	i = -1;
	while (++i < r)
	{
		if (a->top->value >= mid && com[1])
		{
			rotate_stack(a, ASTACK);
			com[0]--;
		}
		else if (a->top->value < mid)
		{
			push_another_stack(a, b, BSTACK);
			com[1]--;
		}
	}
	restore_stack(a, r - 2 - com[0]);
	a_to_b(a, b, r - 2);
	b_to_a(a, b, 2);
}
