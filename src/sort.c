#include "push_swap.h"

void	sort_three(t_stack **head)
{
	t_stack	*max;

	max = stack_max(*head);
	if (is_sorted(*head))
		return ;
	if ((*head) == max)
		ft_ra(head, true);
	else if ((*head)->next == max)
		ft_rra(head, true);
	if (*head != stack_min(*head))
		ft_sa(head, true);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_stacks(*a, *b);
		mv_rotate_a(a, stack_min(*a));
		ft_pb(a, b, true);
	}
}

bool	is_sorted(t_stack *head)
{
	int		x;
	t_stack	*tmp;

	tmp = head;
	x = tmp->value;
	while (tmp)
	{
		if (x > tmp->value)
			return (false);
		x = tmp->value;
		tmp = tmp->next;
	}
	return (true);
}
