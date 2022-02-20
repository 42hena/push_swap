/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:44:24 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:44:26 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_asorted(t_stack *s, int r)
{
	t_dllist	*tmp;
	int			*arr;
	int			i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * r);
	tmp = s->top;
	while (++i < r)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < r - 1)
	{
		if (arr[i] >= arr[i + 1])
		{
			free(arr);
			return (false);
		}
	}
	free(arr);
	return (true);
}

bool	is_bsorted(t_stack *s, int r)
{
	t_dllist	*tmp;
	int			*arr;
	int			i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * r);
	tmp = s->top;
	while (++i < r)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < r - 1)
	{
		if (arr[i] <= arr[i + 1])
		{
			free(arr);
			return (false);
		}
	}
	free(arr);
	return (true);
}
