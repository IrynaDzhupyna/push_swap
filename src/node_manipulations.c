/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:05:42 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 15:43:06 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node  *new_node_create(int *num, int *index)
{
    s_node  *new_node;
    
    new_node = malloc(sizeof(s_node));
    if (!new_node)
        return (NULL);
    new_node->value = *num;
    new_node->index = *index;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

void    node_add_back(s_node **stack, s_node *new_node)
{
    s_node  *temp;

    if (!stack || !new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

int     node_counter(s_node *stack_head)
{
    int i;
    s_node  *current;
    
    i = 0;
    current = stack_head;
    while (current)
    {
        current = current->next;
        i++;
    }
    return (i);
}

s_node  *smallest_node(s_node **stack_head)
{
    s_node  *min;
    s_node  *current;

    current = *stack_head;
    min = current;
    
    while (current->next)
    {
        if (current->value > current->next->value)
            min = current->next;
        current = current->next;
    }
    return (min);
}