#include "push_swap.h"

static void	ft_rotate(t_stack **head);

void	ft_ra(t_stack **head, bool print)
{
	ft_rotate(head);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **head, bool print)
{
	ft_rotate(head);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

static void	ft_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*current;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	*head = first->next;
	first->next = NULL;
}
