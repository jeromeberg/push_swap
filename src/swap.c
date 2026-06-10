#include "push_swap.h"

static void	ft_swap(t_stack **head);

void	ft_sa(t_stack **head, bool print)
{
	ft_swap(head);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **head, bool print)
{
	ft_swap(head);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

static void	ft_swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}
