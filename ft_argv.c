#include "push_swap.h"

static bool	is_char_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void		init_value(long long *sum, int *flag)
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
bool is_int(long long sum)
{
	if (sum > 2147483647 || sum <-2147483648)
		return (false);
	return (true);
}
static bool	is_int_number(char *str, t_stack *a)
{
	long long	sum;
	int			i;
	int			flag;

	i = -1;
	while (str[++i])
	{
		init_value(&sum, &flag);
		while (str[i] == ' ')
			++i;
		sign_handle(str[i], &i, &flag);
		while (str[i] != ' ')
		{
			if (is_char_number(str[i]))
				sum = sum * 10 + str[i] - '0';
			else
				return (false);
			i++;
		}
		if (!is_int)
			return (false);
		insert_stack(a, sum);
		sum = 0;
	}
	return (true);
}

bool	check_argv(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_int_number(argv[i], a))
			return (false);
	}
	return (true);
}
