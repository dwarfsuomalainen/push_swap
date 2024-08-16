/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:34:09 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/16 22:09:53 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function ft_tolong() implemented to checks for
// possible overflows and to convert string to a long value
static long	ft_tolong(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

// function creates a stack with the values from a command line
// flag implemented to indicate that argv in HEAP to be freed
void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (err_syntax(argv[i]))
		{
			err_free(a, argv, flag_argc_2);
		}
		num = ft_tolong(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			err_free(a, argv, flag_argc_2);
		if (err_repeat_num(*a, (int)num))
			err_free(a, argv, flag_argc_2);
		append_node(a, (int)num);
		++i;
	}
	if (flag_argc_2)
		free_arr(argv);
}
