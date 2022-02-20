/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ab_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:37:59 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:38:06 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_min_max_mid(t_stack *a)
{
	rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
	reverse_rotate_stack(a, ASTACK);
}

void	a_mid_min_max(t_stack *a)
{
	swap_stack(a, ASTACK);
}

void	a_mid_max_min(t_stack *a)
{
	rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
	reverse_rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
}

void	a_max_min_mid(t_stack *a)
{
	swap_stack(a, ASTACK);
	rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
	reverse_rotate_stack(a, ASTACK);
}

void	a_max_mid_min(t_stack *a)
{
	swap_stack(a, ASTACK);
	rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
	reverse_rotate_stack(a, ASTACK);
	swap_stack(a, ASTACK);
}
