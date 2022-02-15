/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:32 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 15:16:02 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_int(long long value)
{
	if (value > 2147483647 || value < -2147483648)
		return (false);
	return (true);
}


void	is_int_range(t_stack *a, t_stack *b)
{
	int			size;
	t_dllist	*tmp;
	
	size = a->size;
	tmp = a->top;
	while (size--)
	{
		if (!check_int(tmp->value))
			print_error("Error\nNot INT", a, b);
		tmp = tmp->next;
	}
}
