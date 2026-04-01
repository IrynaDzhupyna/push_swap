/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:51:47 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 17:30:38 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a)|| rrb (reverse rotate b)
    Shift down all elements of stack a by 1.
    The last element becomes the first one.
*/
void reverse_rotate(t_node **stack_head)
{
    t_node *current;
    t_node *new_head;

    current = *stack_head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    new_head = current->next;
    current->next = NULL;
    new_head->next = *stack_head;
    *stack_head = new_head;
}

void    rra(t_node **stack_head_a)
{
    if (!*stack_head_a)
        return ;
    reverse_rotate(stack_head_a);
    write(1, "rra\n", 4);
}

void    rrb(t_node **stack_head_b)
{
    if (!*stack_head_b)
        return ;
    reverse_rotate(stack_head_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_node **stack_head_a, t_node **stack_head_b)
{
    if (!*stack_head_a || !*stack_head_b)
        return ;
    reverse_rotate(stack_head_a);
    reverse_rotate(stack_head_b);
    write(1, "rrr\n", 4);
}