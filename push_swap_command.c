/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:33:39 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/14 12:36:35 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// lowest_rate_node top a
// relative target_node top b

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *lowest_rate_node)
{
	while (*a != lowest_rate_node->target_node && *b != lowest_rate_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *lowest_rate_node)
{
	while (*a != lowest_rate_node->target_node && *b != lowest_rate_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

// move node from a to b
// makes target node show up
// push to a
static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lowest_rate_node;

	lowest_rate_node = return_lowest_rate(*b);
	if (lowest_rate_node->above_median
		&& lowest_rate_node->target_node->above_median)
		rotate_both(a, b, lowest_rate_node);
	else if (!(lowest_rate_node->above_median)
		&& !(lowest_rate_node->target_node->above_median))
		reverse_rotate_both(a, b, lowest_rate_node);
	finish_rotation(b, lowest_rate_node, 'b');
	finish_rotation(a, lowest_rate_node->target_node, 'a');
	pa(a, b, false);
}

// push all nodes to b
// choose lowest_raate_node
// push all back to a in direct order
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				length_a;

	length_a = stack_length(*a);
	if (length_a == 5)
		handle_five(a, b);
	else
	{
		while (length_a-- > 3)
			pb(b, a, false);
	}
	sort_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
