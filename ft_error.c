/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:35:39 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 14:45:11 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_recursive_list(t_dllist *tmp, int size)
{
	if (size == 0)
		return ;
	free_recursive_list(tmp->next, size - 1);
	free(tmp);
}

static void	free_stack(t_stack *tmp)
{
	int			size;
	t_dllist	*list;

	if (tmp == NULL)
		return ;
	if (tmp ->top == NULL)
		return ;
	size = tmp->size;
	list = tmp->top;
	free_recursive_list(list, size - 1);
	free(tmp);
}

static void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	print_error(const char *s, t_stack *a, t_stack *b)
{
	write(1, s, ft_strlen(s));
	free_all(a, b);
	exit(0);
}
