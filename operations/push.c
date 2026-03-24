/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:52 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 15:56:59 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a) || pb (push b)
    Take the first element at the top of X and put it at the top of Y
    Do nothing if b is empty
*/
void push(s_node **dst_head, s_node **src_head)
{
    s_node *temp;
    s_node *new_head;

    if (!src_head || !*src_head || !dst_head)
        return;
    temp = *src_head;
    new_head = (*src_head)->next;
    temp->next = *dst_head;
    *dst_head = temp;
    *src_head = new_head;
}

void    pa(s_node **stack_head_a, s_node **stack_head_b)
{
    if (!*stack_head_b)
        return ;
    push(stack_head_a, stack_head_b);
    write(1, "pa\n", 3);
}

void    pb(s_node **stack_head_a, s_node **stack_head_b)
{
    if (!*stack_head_a)
        return ;
    push(stack_head_b, stack_head_a);
    write(1, "pb\n", 3);
}