/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:51:10 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 15:47:48 by irdzhupy         ###   ########.fr       */
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