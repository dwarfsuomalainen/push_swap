/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:24:42 by rbogoudi          #+#    #+#             */
/*   Updated: 2024/08/12 14:41:57 by rbogoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void swap(t_stack_node **head)
{
    int length;

    length = stack_length(*head);
    if (*head == NULL || head == NULL || length == 1)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}

void    sa(t_stack_node **a, bool checker)
{
    swap(a);
    if (!checker)
        write(1, "sb\n", 3);
}

void    sb(t_stack_node **b, bool checker)
{
    swap(b);
    if (!checker)
        write(1, "sb\n", 3);
}

void    ss(t_stack_node **a, t_stack_node **b, bool checker)
{
    swap(a);
    swap(b);
    if(!checker)
        write(1, "ss\n", 3);
}