#include "push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b);
static void	set_cost_b(t_stack *a, t_stack *b);
static void	set_cheapest(t_stack *b);

/*
 * init_stacks: Init values for every node in stacks
 * a: ptr to head of stack a
 * b: ptr to head of stack b
 */
void	init_stacks(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
	set_cost_b(a, b);
	set_cheapest(b);
}

/*
 * set_index: set index and above_mid for every node in stack
 * head: ptr to head of stack
 */
void	set_index(t_stack *head)
{
	int	i;
	int	mid;

	i = 0;
	if (head == NULL)
		return ;
	mid = stack_len(head) / 2;
	while (head)
	{
		head->index = i;
		if (i <= mid)
			head->above_mid = true;
		else
			head->above_mid = false;
		head = head->next;
		++i;
	}
}

/*
 * set_target_b: Set target for each node in stack b
 * - For each node in b,
	iterates through a to find best target
	(bigger than b and cheaper than cheapest_value)
 * - If no target found then the target
	is set to min of a (bc it means that b
	is future smallest of a)
 * a: ptr to head of stack a
 * b: ptr to head of stack b
 */
static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	cheapest_value;

	while (b)
	{
		cheapest_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < cheapest_value)
			{
				cheapest_value = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (cheapest_value == LONG_MAX)
			b->target = stack_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

/*
 * set_cost_b: Calc and set the cost to move each node in b to target
 * (cost to move b to top + cost to move a to top)
 * a: ptr to head of stack a
 * b: ptr to head of stack b
 */
static void	set_cost_b(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (!(b->above_mid))
			b->cost = len_b - (b->index);
		else
			b->cost = b->index;
		if (b->target->above_mid)
			b->cost += b->target->index;
		else
			b->cost += len_a - (b->target->index);
		b = b->next;
	}
}

/*
 * set_cheapest: Set cheapest move in stack
 * head: ptr to head of stack
 */
static void	set_cheapest(t_stack *head)
{
	t_stack			*cheapest;
	unsigned int	value;

	if (head == NULL)
		return ;
	value = UINT_MAX;
	while (head)
	{
		if ((unsigned int)head->cost < value)
		{
			value = head->cost;
			cheapest = head;
		}
		head = head->next;
	}
	cheapest->cheapest = true;
}
