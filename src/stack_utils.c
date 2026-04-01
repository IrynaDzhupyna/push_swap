/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:57:49 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 17:59:38 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     stack_is_sorted(t_node *stack_head)
{
    t_node  *current;

    current = stack_head;
    while (current->next)
    {
        if ((current->value) > (current->next->value))
            return (0);
        current = current->next;
    }
    return (1);
}

void    free_stack(t_node *stack_head)
{
    if (!stack_head)
        return ;
    free_stack(stack_head->next);
    free(stack_head);
}

int    set_indexes(t_node *stack_head)
{
    int i;
    int stack_size;
    t_node  *next_to_check;
    t_node  *current;

    if (!stack_head)
        return (0);
    current = stack_head;
    stack_size = 0;
    while (current)
    {
        i = 0;
        next_to_check = stack_head;
        stack_size++;
        while (next_to_check)
        {
            if (current->value > next_to_check->value)
                i++;
            next_to_check = next_to_check->next;
        }
        current->index = i;
        current = current->next;
    }
    return (stack_size);
}

void    print_stack(t_node *stack_head)
{
    int i;
    t_node  *temp;
    
    i = 0;
    temp = stack_head;
    while (temp)
    {
        printf("Node %d value is %d index is %d\n", i, temp->value, temp->index);
        i++;
        temp = temp->next;
    }
}