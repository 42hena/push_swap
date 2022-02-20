/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:23 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 14:37:48 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info(t_info *info, t_stack *tmp, int r)
{
	info->command[0] = 0;
	info->command[1] = 0;
	info->command[2] = 0;
	info->r = r;
	find_pivot(tmp, info);
}

static void	get_bcommand(t_stack *b, t_info *info)
{
	t_dllist	*tmp;
	int			size;

	size = info->r;
	tmp = b->top;
	while (size--)
	{
		if (tmp->value < info->pivot[1])
			info->command[0]++;
		else
		{
			info->command[1]++;
			if (tmp->value < info->pivot[0])
				info->command[2]++;
		}
		tmp = tmp->next;
	}
}

static int	get_info(t_stack *a, t_stack *b, t_info info)
{
	while (info.r--)
	{
		if (b->top->value < info.pivot[1] && info.command[1])
		{
			rotate_stack(b, BSTACK);
			info.command[0]--;
		}
		else if (b->top->value >= info.pivot[1])
		{
			push_another_stack(b, a, ASTACK);
			info.command[1]--;
			if (a->top->value < info.pivot[0] && a->size != 1)
			{
				rotate_stack(a, ASTACK);
				info.command[2]--;
			}
		}
	}
	return (info.command[0]);
}

static void	reverse(t_stack *a, t_stack *b, t_info info, int rev)
{
	int	i;

	i = 0;
	while (i < rev && i < info.command[2])
	{
		reverse_rotate_togather(a, b);
		++i;
	}
	while (i < rev)
	{
		reverse_rotate_stack(b, BSTACK);
		++i;
	}
	while (i < info.command[2])
	{
		reverse_rotate_stack(a, ASTACK);
		++i;
	}
}

void	b_to_a(t_stack *a, t_stack *b, int r)
{
	t_info	info;
	int		rev;
	int		i;

	i = -1;
	if (is_bsorted(b, r))
	{
		while (++i < r)
			push_another_stack(b, a, ASTACK);
		return ;
	}
	if (r <= 5)
	{
		handle_b_under_five(a, b, r);
		return ;
	}
	init_info(&info, b, r);
	get_bcommand(b, &info);
	rev = get_info(a, b, info);
	a_to_b(a, b, info.command[1] - info.command[2]);
	reverse(a, b, info, info.command[0] - rev);
	a_to_b(a, b, info.command[2]);
	b_to_a(a, b, info.command[0]);
}
