/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:05:42 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/30 12:24:43 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node  *new_node_create(int *num)
{
    s_node  *new_node;
    
    new_node = malloc(sizeof(s_node));
    if (!new_node)
        return (NULL);
    new_node->value = *num;
    new_node->index = 0;
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

int get_node_position(s_node *stack_head, s_node *target_node)
{
    int i;

    i = 0;
    while (stack_head)
    {
        if (stack_head == target_node)
            return (i);
        stack_head = stack_head->next;
        i++;
    }
    return (-1);
}

s_node  *smallest_node(s_node *stack_head)
{
    s_node  *min;
    s_node  *current;

    current = stack_head;
    min = stack_head;
    while (current)
    {
        if (current->value < min->value)
            min = current;
        current = current->next;
    }
    return (min);
}

void    node_indexation(s_node *new_node, s_node *stack_head)
{
    s_node  *temp;
    int i;
    
    if (!stack_head)
        return ;
    temp = stack_head;
    i = 1;
    while (temp->next)
    {
        if (temp->value > new_node->value)
        {
            temp->index = i;
            i++;
            temp = temp->next;  
        }
    }
}