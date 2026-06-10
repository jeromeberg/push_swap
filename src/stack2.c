#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*get_cheapest(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->above_mid = false;
	new_node->cost = 0;
	new_node->target = NULL;
	new_node->cheapest = false;
	new_node->next = NULL;
	return (new_node);
}

void	append_stack(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
		exit_error(head);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	stack_last(*head)->next = new_node;
}
