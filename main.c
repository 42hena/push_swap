/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:29 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 15:13:53 by hena             ###   ########.fr       */
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
	//printf("%p %p %p %d %p %p %p %d\n", a, a->top, a->bottom, a->size, b, b->top, b->bottom, b->size);
	if (!check_parameter(argc, argv, a))
		print_error("Error\nParameter", a, b);
	t_dllist *tmp = a->top;
	int size = a->size;
	printf("size: [%d]\n", a->size);
	while (size--)
	{
		printf("value:[%d]\n", tmp->value);
		tmp = tmp->next;
	}
	check_duplicate(a, b);
	is_int_range(a, b);
	check_sort(a, b);
	a_to_b(a, b, a->size);
	print_error("", a, b);
}
