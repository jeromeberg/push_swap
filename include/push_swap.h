#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	bool			above_mid;
	int				cost;
	struct s_stack	*target;
	bool			cheapest;
	struct s_stack	*next;
}					t_stack;

// main

int					main(int argc, char **argv);
void				push_swap(t_stack **a, t_stack **b);

// input

t_stack				*fill_stack(char **av, bool split);

// stack

t_stack				*stack_last(t_stack *head);
t_stack				*stack_before_last(t_stack *head);
t_stack				*stack_min(t_stack *head);
t_stack				*stack_max(t_stack *head);
int					stack_len(t_stack *head);
void				free_stack(t_stack **stack);
t_stack				*get_cheapest(t_stack *head);
t_stack				*create_node(int value);
void				append_stack(t_stack **head, int value);

// init

void				init_stacks(t_stack *a, t_stack *b);
void				set_index(t_stack *stack);

// moves

void				ft_mv_pa(t_stack **a, t_stack **b);
void				mv_rotate_a(t_stack **head, t_stack *node);

// sort

void				sort_three(t_stack **head);
void				handle_five(t_stack **a, t_stack **b);
bool				is_sorted(t_stack *head);

// utils

int					ft_atoi2(const char *str, bool *overflow);
void				ft_free_split(char **array);
void				exit_error(t_stack **head);
bool				is_int(char *str);

/* operations */

// push

void				ft_pa(t_stack **a, t_stack **b, bool print);
void				ft_pb(t_stack **a, t_stack **b, bool print);

// swap

void				ft_sa(t_stack **head, bool print);
void				ft_sb(t_stack **head, bool print);
void				ft_ss(t_stack **a, t_stack **b, bool print);

// rotate

void				ft_ra(t_stack **head, bool print);
void				ft_rb(t_stack **head, bool print);
void				ft_rr(t_stack **a, t_stack **b, bool print);

// reverse rotate

void				ft_rra(t_stack **head, bool print);
void				ft_rrb(t_stack **head, bool print);
void				ft_rrr(t_stack **a, t_stack **b, bool print);

#endif