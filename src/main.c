#include "push_swap.h"

static bool	is_str_empty(char *str);
// static bool	has_empty_arg(char **av);
static void	clean_exit(t_stack **a, t_stack **b, bool split, char **tab);
void		check_args(int ac, char **av);

/*
 * main
 * - If argv is single string: split and set split to true,
	check that it's not empty
 * - Create and fill stack a with values
 * - Sort stacks
 * - Free stacks (and tab if needed)
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;
	bool	split;

	tab = NULL;
	a = NULL;
	b = NULL;
	split = false;
	if (argc == 1)
		return (0);
	check_args(argc, argv);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		split = true;
	}
	else
		tab = argv;
	a = fill_stack(tab, split);
	push_swap(&a, &b);
	clean_exit(&a, &b, split, tab);
	return (0);
}

/*
 * push_swap: Sort stacks
 * - Use handle_five() if stack size is 5
 * - Push stack a to b until A has 3 nodes left
 * - Sort three
 * - While stack b is not empty: init and move to a
 * - Rotate min of a to the top if it's not
 * a: ptr to ptr to head of stack a
 * b: ptr to ptr to head of stack b
 */
void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;

	if (is_sorted(*a))
		return ;
	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
		{
			ft_pb(a, b, true);
		}
	}
	sort_three(a);
	while (*b)
	{
		init_stacks(*a, *b);
		ft_mv_pa(a, b);
	}
	set_index(*a);
	mv_rotate_a(a, stack_min(*a));
}

static bool	is_str_empty(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static void	clean_exit(t_stack **a, t_stack **b, bool split, char **tab)
{
	if (split)
		ft_free_split(tab);
	free_stack(a);
	free_stack(b);
}

void	check_args(int ac, char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (is_str_empty(av[i]))
			exit_error(NULL);
		if (ac > 2 && i > 1 && !is_int(av[i]))
			exit_error(NULL);
		i++;
	}
	return ;
}
