#include "push_swap.h"

t_stack	*stack_last(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return (NULL);
	current = head;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_stack	*stack_before_last(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return (NULL);
	current = head;
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}

t_stack	*stack_min(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*x;

	if (head == NULL)
		return (NULL);
	tmp = head;
	x = head;
	while (tmp != NULL)
	{
		if (tmp->value < x->value)
			x = tmp;
		tmp = tmp->next;
	}
	return (x);
}

t_stack	*stack_max(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*x;

	if (head == NULL)
		return (NULL);
	tmp = head;
	x = head;
	while (tmp != NULL)
	{
		if (tmp->value > x->value)
			x = tmp;
		tmp = tmp->next;
	}
	return (x);
}

int	stack_len(t_stack *head)
{
	int		i;
	t_stack	*current;

	if (head == NULL)
		return (0);
	i = 0;
	current = head;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
