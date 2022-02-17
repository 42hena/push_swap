/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:12 by hena              #+#    #+#             */
/*   Updated: 2022/02/17 19:04:51 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, t_info *info)
{
	int	i;
	int	j;
	int	tmp;
	int	size;

	size = info->r;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	info->pivot[0] = arr[size * 2 / 3];
	info->pivot[1] = arr[size / 3];
}

void	find_pivot(t_stack *tmp, t_info *info)
{
	int			i;
	int			*array;
	t_dllist	*list;
	int			size;

	i = 0;
	array = (int *)malloc(sizeof(int) * info->r);
	list = tmp->top;
	size = info->r;
	while (size--)
	{
		array[i++] = list->value;
		list = list->next;
	}
	bubble_sort(array, info);
	free(array);
}
