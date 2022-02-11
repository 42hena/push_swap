/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:38 by hena              #+#    #+#             */
/*   Updated: 2022/02/07 17:21:45 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_argc(int argc)
{
	if (argc < 2)
		return (false);
	return (true);
}

static bool	is_char_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static bool	is_int_number(char *str)
{
	long long sum;
	int	i;

	i = -1;
	sum = 0;
	while (str[++i])
	{
		if (!is_char_number(str[i]))
			return (false);
		sum = sum * 10 + str[i] - '0';
	}
	if (sum > 2147483647 || sum < 0)
		return (false);
	return (true);
}

static bool	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_int_number(argv[i]))
			return (false);
	}
	return (true);
}

void	check_parameter(int argc, char **argv)
{
	if (!check_argc(argc))
		exit(0);
	if (!check_argv(argc, argv))
		exit(0);
}