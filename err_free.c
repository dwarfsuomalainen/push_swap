/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:43:40 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/12 12:22:26 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function implemented to free an
// array created by ft_split() function
void	free_arr(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

// function implemented to free a stack
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

// array forced to be equal to argv
// because of that it starts from -1
void	err_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_arr(argv);
	write(2, "Error\n", 6);
	exit(1);
}

// Syntax errors checker
int	err_syntax(char *str_num)
{
	if (!(*str_num == '+' || *str_num == '-' || (*str_num >= '0'
				&& *str_num <= '9')))
		return (1);
	if ((*str_num == '+' || *str_num == '-') && !(str_num[1] >= '0'
			&& str_num[1] <= '9'))
		return (1);
	while (*++str_num)
	{
		if (!(*str_num >= '0' && *str_num <= '9'))
			return (1);
	}
	return (0);
}

// Repeptitinve numbers in the stack checker
int	err_repeat_num(t_stack_node *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}
