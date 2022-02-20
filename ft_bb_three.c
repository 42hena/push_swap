/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bb_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:13:53 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:13:54 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_min_mid_max(t_stack *b)
{
	swap_stack(b, BSTACK);
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
}

void	b_min_max_mid(t_stack *b)
{
	swap_stack(b, BSTACK);
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
}

void	b_mid_min_max(t_stack *b)
{	
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
}

void	b_mid_max_min(t_stack *b)
{
	swap_stack(b, BSTACK);
}

void	b_max_min_mid(t_stack *b)
{
	rotate_stack(b, BSTACK);
	swap_stack(b, BSTACK);
	reverse_rotate_stack(b, BSTACK);
}
