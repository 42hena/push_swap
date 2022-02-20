/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:22:58 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 14:37:27 by hena             ###   ########.fr       */
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

static void	get_acommand(t_stack *a, t_info *info)
{
	t_dllist	*tmp;
	int			size;

	size = info->r;
	tmp = a->top;
	while (size--)
	{
		if (tmp->value >= info->pivot[0])
			info->command[0]++;
		else
		{
			info->command[1]++;
			if (tmp->value >= info->pivot[1])
				info->command[2]++;
		}
		tmp = tmp->next;
	}
}

static int	get_info(t_stack *a, t_stack *b, t_info info)
{
	while (info.r--)
	{
		if (a->top->value >= info.pivot[0] && info.command[1])
		{
			rotate_stack(a, ASTACK);
			info.command[0]--;
		}
		else if (a->top->value < info.pivot[0])
		{
			push_another_stack(a, b, BSTACK);
			info.command[1]--;
			if (b->top->value >= info.pivot[1] && b->size != 1)
			{
				rotate_stack(b, BSTACK);
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
		reverse_rotate_stack(a, ASTACK);
		++i;
	}
	while (i < info.command[2])
	{
		reverse_rotate_stack(b, BSTACK);
		++i;
	}
}

void	a_to_b(t_stack *a, t_stack *b, int r)
{
	t_info	info;
	int		rev;

	if (is_asorted(a, r))
		return ;
	if (r <= 5)
	{
		handle_a_under_five(a, b, r);
		return ;
	}
	init_info(&info, a, r);
	get_acommand(a, &info);
	rev = get_info(a, b, info);
	reverse(a, b, info, info.command[0] - rev);
	a_to_b(a, b, info.command[0]);
	b_to_a(a, b, info.command[2]);
	b_to_a(a, b, info.command[1] - info.command[2]);
}
