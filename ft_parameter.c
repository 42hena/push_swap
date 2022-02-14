/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:38 by hena              #+#    #+#             */
/*   Updated: 2022/02/14 19:13:48 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_parameter(int argc, char **argv, t_stack *a)
{
	if (!check_argc(argc))
	{
		printf("argc\n");
		//exit(0);
	}
	if (!check_argv(argc, argv, a))
	{
		printf("argv\n");
		//exit(0);
	}
}
