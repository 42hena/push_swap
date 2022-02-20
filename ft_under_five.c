/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:38:42 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:39:37 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_under_five(t_stack *a, t_stack *b, int r)
{
	int	size;

	size = a->size;
	if (r <= 1)
		return ;
	else if (r == 2)
		a_two(a);
	else if (r == 3)
		as_three(a, 3);
	else if (r == 4 || r == 5)
		as_five(a, b, r);
}
