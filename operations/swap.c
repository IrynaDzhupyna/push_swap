/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:48:59 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 18:03:23 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a) || sb (swap b)
    Swap the first 2 elements at the top of stack X.
    Do nothing if there is only one element or none.
*/
void swap(s_node **stack_head)
{
    s_node *first;
    s_node *second;

    if (!stack_head || !*stack_head || !(*stack_head)->next)
        return;
    first = *stack_head;
    second = (*stack_head)->next;
    first->next = second->next;
    second->next = first;
    *stack_head = second;
}

void    sa(s_node **stack_head_a)
{
    if (!*stack_head_a)
        return ;
    swap(stack_head_a);
    write(1, "sa\n", 3);
}

void    sb(s_node **stack_head_b)
{
    if (!*stack_head_b)
        return ;
    swap(stack_head_b);
    write(1, "sb\n", 3);
}

void    ss(s_node **stack_head_a, s_node **stack_head_b)
{
    if (!*stack_head_a || !*stack_head_b)
        return ;
    swap(stack_head_a);
    swap(stack_head_b);
    write(1, "ss\n", 3);
}