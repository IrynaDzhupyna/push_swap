/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:51:10 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 18:03:44 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a) || rb(rotate b)
    Shift up all elements of stack a by 1.
    The first element becomes the last one.
*/
void rotate(s_node **stack_head)
{
    s_node *temp;
    s_node *new_head;
    s_node *current;

    if (!stack_head || !*stack_head || (*stack_head)->next == NULL)
        return;
    temp = *stack_head;
    new_head = (*stack_head)->next;
    current = *stack_head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    *stack_head = new_head;
}

void    ra(s_node **stack_head_a)
{
    if (!*stack_head_a)
        return ;
    rotate(stack_head_a);
    write(1, "ra\n", 3);
}

void    rb(s_node **stack_head_b)
{
    if (!*stack_head_b)
        return ;
    rotate(stack_head_b);
    write(1, "rb\n", 3);
}

void    rr(s_node **stack_head_a, s_node **stack_head_b)
{
    if (!*stack_head_a || !*stack_head_b)
        return ;
    rotate(stack_head_a);
    rotate(stack_head_b);
    write(1, "rr\n", 3);
}