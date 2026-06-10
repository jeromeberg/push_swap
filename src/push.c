#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest);

void	ft_pa(t_stack **a, t_stack **b, bool print)
{
	ft_push(b, a);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **a, t_stack **b, bool print)
{
	ft_push(a, b);
	if (print)
		ft_putstr_fd("pb\n", 1);
}

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
