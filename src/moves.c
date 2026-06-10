#include "push_swap.h"

static void	mv_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
static void	mv_reverse_rotate_both(t_stack **a, t_stack **b,
				t_stack *cheapest_node);
static void	mv_rotate_b(t_stack **head, t_stack *node);

static void	mv_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		ft_rr(a, b, true);
	set_index(*a);
	set_index(*b);
}

static void	mv_reverse_rotate_both(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		ft_rrr(a, b, true);
	set_index(*a);
	set_index(*b);
}

void	mv_rotate_a(t_stack **head, t_stack *node)
{
	while (*head != node)
	{
		if (node->above_mid)
			ft_ra(head, true);
		else
			ft_rra(head, true);
	}
}

static void	mv_rotate_b(t_stack **head, t_stack *node)
{
	while (*head != node)
	{
		if (node->above_mid)
			ft_rb(head, true);
		else
			ft_rrb(head, true);
	}
}

/*
 * ft_mv_pa: Move cheapest node from stack b to stack a (pa)
 * - if rotation is in the same direction: use rr or rrr
 * - finish rotation
 * a: ptr to ptr to head of stack a
 * b: ptr to ptr to head of stack b
 */
void	ft_mv_pa(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_mid && cheapest_node->target->above_mid)
		mv_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_mid) && !(cheapest_node->target->above_mid))
		mv_reverse_rotate_both(a, b, cheapest_node);
	mv_rotate_a(a, cheapest_node->target);
	mv_rotate_b(b, cheapest_node);
	ft_pa(a, b, true);
}
