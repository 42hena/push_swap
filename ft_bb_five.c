/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bb_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:45:43 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 14:46:35 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_com(int com[])
{
	com[0] = 0;
	com[1] = 0;
}

static void	get_com(t_stack *b, int com[], int r, int mid)
{
	int			i;
	t_dllist	*tmp;

	i = -1;
	tmp = b->top;
	while (++i < r)
	{
		if (tmp->value < mid)
			com[0]++;
		else
			com[1]++;
		tmp = tmp->next;
	}
}

static void	restore_stack(t_stack *b, int r)
{
	int	i;

	i = -1;
	while (++i < r)
		reverse_rotate_stack(b, BSTACK);
}

void	bb_five(t_stack *a, t_stack *b, int r)
{
	int			arr[5];
	int			mid;
	int			com[2];
	int			i;

	init(b, arr, r);
	mid = getmidvalue(arr, r);
	get_com(b, com, r, mid);
	i = -1;
	while (++i < r)
	{
		if (b->top->value < mid && com[1])
		{
			rotate_stack(b, BSTACK);
			com[0]--;
		}
		else if (b->top->value >= mid)
		{
			push_another_stack(b, a, ASTACK);
			com[1]--;
		}
	}
	restore_stack(b, r - 2 - com[0]);
	a_to_b(a, b, r - 2);
	b_to_a(a, b, 2);
}
