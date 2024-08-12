/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:37:20 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/12 19:59:20 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function checks if stack been sorted
bool    stack_sorted(t_stack_node *stack)
{
    if (stack == NULL)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

static t_stack_node *find_highest(t_stack_node *stack)
{
    int             highest;
    t_stack_node    *highest_node;
    
    if (stack == NULL)
        return (NULL);
    highest = INT_MIN;
    while (stack)
    {
        if (stack->value > highest)
            {
                highest = stack->value;
                highest_node = stack;
            }
            stack = stack->next;
    }
    return (highest_node);
}

/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
void    sort_sort(t_stack_node **a)
{
    t_stack_node    *highest_node;

    highest_node = find_highest(*a);
    if (*a == highest_node)
        ra(a, false);
    else if ((*a)->next == highest_node)
        rra(a,false);
    if ((*a)->value > (*a)->next->value)
        sa(a,false);    
}
//Handle input five
void    handle_five(t_stack_node **a, t_stack_node **b)
{
    while (stack_length(*a) > 3)
    {
        init_nodes(*a, *b);
        finish_rotation(a, find_smallest(*a), 'a');
        pb(b, a, false);
    }
}