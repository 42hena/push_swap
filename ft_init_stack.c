/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:40:32 by hena              #+#    #+#             */
/*   Updated: 2022/02/20 13:40:33 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_number(char *str)
{
	long long	sum;

	sum = 0;
	while (*str)
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum);
}

t_dllist	*init_dllist(long long num)
{
	t_dllist	*tmp;

	tmp = (t_dllist *)malloc(sizeof(t_dllist));
	tmp->prev = tmp;
	tmp->next = tmp;
	tmp->value = num;
	return (tmp);
}

void	insert_stack(t_stack *stack, long long sum)
{
	t_dllist	*tmp;
	t_dllist	*iter;

	tmp = init_dllist(sum);
	if (stack->size == 0)
	{
		stack->top = tmp;
		stack->bottom = tmp;
		stack->size++;
	}
	else
	{
		iter = stack->bottom;
		tmp->prev = iter;
		tmp->next = iter->next;
		iter->next->prev = tmp;
		iter->next = tmp;
		stack->bottom = tmp;
		stack->size++;
	}
}

t_stack	*init_stack(void)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (false);
	tmp->top = NULL;
	tmp->bottom = NULL;
	tmp->size = 0;
	return (tmp);
}
