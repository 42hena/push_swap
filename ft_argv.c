/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:35:33 by hena              #+#    #+#             */
/*   Updated: 2022/02/15 14:48:10 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_char_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static void	init_value(long long *sum, int *flag)
{
	*sum = 0;
	*flag = 1;
}

static void	sign_handle(char c, int *i, int *flag)
{
	if (c == '+' || c == '-')
		(*i)++;
	if (c == '-')
		*flag = -1;
}

static bool	ft_split(char *str, t_stack *a)
{
	long long	sum;
	int			i;
	int			flag;

	i = 0;
	while (str[i])
	{
		init_value(&sum, &flag);
		while (str[i] == ' ')
			++i;
		sign_handle(str[i], &i, &flag);
		while (str[i] && str[i] != ' ')
		{
			if (is_char_number(str[i]))
				sum = sum * 10 + str[i] - '0';
			else
				return (false);
			++i;
		}
		if (!(sum > 2147483647 || sum < -2147483648))
			return (false);
		insert_stack(a, sum);
	}
	return (true);
}

bool	check_argv(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_split(argv[i], a))
			return (false);
	}
	return (true);
}
