/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:43:23 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/13 14:19:09 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_node
{
	int					value;
	int					current_position;
	int					last_index;
	int					push_rate;
	bool				above_median;
	bool				lowest_rate;
	struct stack_node	*target_node;
	struct stack_node	*next;
	struct stack_node	*prev;
}						t_stack_node;

// error hanlers
void					free_arr(char **argv);
void					free_stack(t_stack_node **stack);
void					err_free(t_stack_node **a, char **argv,
							bool flag_argc_2);
int						err_syntax(char *str_nbr);
int						err_repeat_num(t_stack_node *a, int nbr);

// building stack
void					stack_init(t_stack_node **a, char **argv,
							bool flag_argc_2);
void					set_current_position(t_stack_node *stack);
void					set_rate(t_stack_node *a, t_stack_node *b);
void					set_smallest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);

// utilities for linked lists
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_lowest_rate(t_stack_node *stack);
int						stack_length(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
void					finish_rotation(t_stack_node **s, t_stack_node *n,
							char c);

// algorytms
void					sort_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);

// commands
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif
