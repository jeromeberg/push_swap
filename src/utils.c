#include "push_swap.h"

static bool	is_overflow(long long res, int sign);

/*
 * is_overflow: Check if result is overflow
 * res: number
 * sign: 1 (positive), -1 (negative)
 * Returns: true if overflow, false
 */
static bool	is_overflow(long long res, int sign)
{
	long long	negative_res;

	if (sign == -1)
	{
		negative_res = res * -1;
		if (negative_res < INT_MIN)
			return (true);
	}
	else if (sign == 1 && res > INT_MAX)
		return (true);
	return (false);
}

/*
 * ft_atoi2: Converts str to int while checking for overflow
 * str: string to be converted
 * overflow: ptr to bool overflow
 * Returns: result, 0 if overflow and sets overflow to true
 */
int	ft_atoi2(const char *str, bool *overflow)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if (is_overflow(res, sign))
		{
			*overflow = true;
			return (0);
		}
		str++;
	}
	return ((int)(res * sign));
}

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_error(t_stack **head)
{
	free_stack(head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*
 * is_int: Check if str is int
 * Pass -/+ signs and check if str is digit
 * Fix: return false if input is only sign without digits
 * str: the string to check
 * Returns: true if str is int / false
 */
bool	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (false);
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}
