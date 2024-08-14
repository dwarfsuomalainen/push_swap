/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:35:10 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/14 12:39:51 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sets current position of every node
// in the current state
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	central;

	i = 0;
	if (stack == NULL)
		return ;
	central = stack_length(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= central)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR
 *  With this function every node in b gets its target node in a
 */
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// sets rate to push node
// b -> a
// Rate check for relative position in stack
// for every node and setting a respective raate.
void	set_rate(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(a);
	len_b = stack_length(b);
	while (b)
	{
		b->push_rate = b->current_position;
		if (!(b->above_median))
			b->push_rate += len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_rate += b->target_node->current_position;
		else
			b->push_rate += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

// to flag the smallest rated node
// in the current stacks
void	set_smallest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_rate < best_match_value)
		{
			best_match_value = b->push_rate;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->lowest_rate = true;
}

// Everything we need to push
// relative positions
// target node, b node to turn up
// rate for every conf
// lowest rate for current conf
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_rate(a, b);
	set_smallest(b);
}
