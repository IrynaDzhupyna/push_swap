/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:51:47 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/18 11:35:24 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a)|| rrb (reverse rotate b)
    Shift down all elements of stack a by 1.
    The last element becomes the first one.
*/
void reverse_rotate(s_node **stack_head)
{
    s_node *current;
    s_node *last;
    s_node *new_head;

    current = *stack_head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    last = current;
    new_head = current->next;
    current->next = NULL;
    new_head->next = *stack_head;
    *stack_head = new_head;
    print_list(*stack_head);
}