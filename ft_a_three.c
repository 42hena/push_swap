/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:35:22 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 16:26:49 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_arr(int arr[], int r, t_dllist *tmp)
{
	int	i;

	i = 0;
	while (r--)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		++i;
	}
}

void	a_two(t_stack *a)
{
	int			arr[2];
	t_dllist	*tmp;

	tmp = a->top;
	arr[0] = tmp->value ;
	arr[1] = tmp->next->value;
	if (arr[0] > arr[1])
		swap_stack(a, ASTACK);
	return ;
}

void	as_three(t_stack *a, int r)
{
	int	arr[3];

	init_arr(arr, r, a->top);
	if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		swap_stack(a, ASTACK);
		rotate_stack(a, ASTACK);
	}
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		swap_stack(a, ASTACK);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		reverse_rotate_stack(a, ASTACK);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		rotate_stack(a, ASTACK);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		rotate_stack(a, ASTACK);
		swap_stack(a, ASTACK);
	}
}

void	ab_three(t_stack *a, int r)
{
	int	arr[3];

	init_arr(arr, r, a->top);
	if (arr[0] < arr[2] && arr[2] < arr[1])
		a_min_max_mid(a);
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		a_mid_min_max(a);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		a_mid_max_min(a);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		a_max_min_mid(a);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
		a_max_mid_min(a);
}

void	a_under_three(t_stack *a, t_stack *b, int r)
{
	int	size;

	size = a->size;
	if (r <= 1)
		return ;
	else if (r == 2)
		a_two(a);
	else if (r == 3)
	{
		if (size > 3)
			ab_three(a, 3);
		else
			as_three(a, 3);
	}
}
