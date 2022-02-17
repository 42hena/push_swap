/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:29 by hena              #+#    #+#             */
/*   Updated: 2022/02/17 19:34:40 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	ret;

	a = init_stack();
	b = init_stack();
	if (!check_parameter(argc, argv, a))
		print_error("Error\nParameter", a, b);
	check_duplicate(a, b);
	is_int_range(a, b);
	check_sort(a, b);
	if (a->size <= 5)
	{
		a_under_five(a, b, a->size);
		print_error("", a, b);
	}
	a_to_b(a, b, a->size);
	int size = a->size;
	t_dllist *tmp = a->top;
	while (size--)
	{
		printf("[%d]", tmp->value);
		tmp = tmp->next;
	}
	print_error("", a, b);
}
