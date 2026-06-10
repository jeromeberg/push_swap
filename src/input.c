#include "push_swap.h"

static void	exit_fillstack(bool split, char **av, t_stack *head);
static bool	has_dup(t_stack *head, int value);

/*
 * fill_stack: Create stack from arguments
 * av: arguments
 * split: were args splitted (to know whether or not to ignore av[0])
 * Returns: pointer to head of stack, NULL if error.
 */
t_stack	*fill_stack(char **av, bool split)
{
	t_stack	*head;
	int		value;
	int		i;
	bool	overflow;

	i = 0;
	value = 0;
	head = NULL;
	overflow = false;
	if (av == NULL)
		exit_fillstack(split, av, head);
	if (!split)
		i = 1;
	while (av[i] != NULL)
	{
		if (!is_int(av[i]))
			exit_fillstack(split, av, head);
		value = ft_atoi2(av[i], &overflow);
		if (has_dup(head, value) || overflow)
			exit_fillstack(split, av, head);
		append_stack(&head, value);
		i++;
	}
	return (head);
}

/*
 * has_dup: Check if number is already in the stack (duplicate)
 * head: ptr to head of stack
 * value: the value to check
 * Returns: true if value is duplicate / false
 */
static bool	has_dup(t_stack *head, int value)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}

static void	exit_fillstack(bool split, char **av, t_stack *head)
{
	if (split)
		ft_free_split(av);
	exit_error(&head);
}
