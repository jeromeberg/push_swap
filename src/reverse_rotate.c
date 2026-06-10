#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **head);

void	ft_rra(t_stack **head, bool print)
{
	ft_reverse_rotate(head);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **head, bool print)
{
	ft_reverse_rotate(head);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, bool print)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}

static void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = stack_last(*head);
	before_last = stack_before_last(*head);
	tmp = *head;
	*head = last;
	(*head)->next = tmp;
	before_last->next = NULL;
}
