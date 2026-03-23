/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:48:59 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 17:13:06 by irdzhupy         ###   ########.fr       */
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