/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:12 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 14:30:46 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	find_min_max(t_stack *tmp, int size, int pivot[2])
// {
// 	int			maxValue;
// 	int			minValue;
// 	t_dllist	*list;

// 	maxValue = INTMIN;
// 	minValue = INTMAX;
// 	list = tmp->top;
// 	while (size--)
// 	{
// 		if (minValue > list->value)
// 			minValue = list->value;
// 		if (maxValue < list->value)
// 			maxValue = list->value;
// 		list = list->next;
// 	}
// 	pivot[0] = (maxValue + minValue) / 2;
// 	pivot[1] = (pivot[0] + minValue) / 2;
// }


void	bubble(int *arr, int size, int pivot[2])
{
	int	i;
	int	j;
	int	tmp;

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
	pivot[0] = arr[size * 2 / 3];
	pivot[1] = arr[size / 3];
}

void	find_min_max(t_stack *tmp, int size, int pivot[2])
{
	int			i;
	int			*arr;
	t_dllist	*list;

	i = 0;
	arr = malloc(sizeof(int) * size);
	list = tmp->top;
	while (size--)
	{
		arr[i] = list->value;
		list = list->next;
	}
	bubble(arr, tmp->size, pivot);
	free(arr);
}
