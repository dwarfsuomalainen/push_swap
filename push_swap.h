/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:43:23 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/12 13:33:32 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct  stack_node
{
    int					value;
	int					current_position;
	int 				last_index;
	int					push_rate;
	bool				above_median;
	bool				lowest_rate;
	struct  stack_node	*target_node;
	struct	stack_node	*next;
	struct	stack_node	*prev;
}	t_stack_node;

#endif
