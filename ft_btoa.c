/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:23 by hena              #+#    #+#             */
/*   Updated: 2022/02/17 21:12:01 by hena             ###   ########.fr       */
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
		if (b->top->value < info.pivot[1] && info.command[1])//수정 필요
		{
			rotate_stack(b, BSTACK);
			info.command[0]--;
		}
		else if (b->top->value >= info.pivot[1])
		{
			push_another_stack(b, a, ASTACK);
			info.command[1]--;
			if (b->top->value < info.pivot[0])
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

	//printf("a in r: [%d]\n", r);
    //print_stack(a);	
    //print_stack(b);	
	if (r <= 3)
	{
		b_under_three(a, b, r);
		return ;
	}
	init_info(&info, b, r);
	//printf("p1:[%d], p2:[%d]\n", info.pivot[0], info.pivot[1]);
	get_bcommand(b, &info);
	//printf("prev %d %d %d\n", info.command[0], info.command[1], info.command[2]);
	rev = get_info(a, b, info);
	//printf("next %d %d %d\n", info.command[0], info.command[1], info.command[2]);
	a_to_b(a, b, info.command[1] - info.command[2]);
	reverse(a, b, info, rev);
	a_to_b(a, b, info.command[2]);
	b_to_a(a, b, info.command[0]);
}
