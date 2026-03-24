/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:57:49 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 13:43:51 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return:
// 1 if sorted
// 0 if not
int     stack_is_sorted(s_node *stack_head)
{
    s_node  *current;

    current = stack_head;
    while (current->next)
    {
        if ((current->value) > (current->next->value))
            return (0);
        current = current->next;
    }
    return (1);
}

void    print_stack(s_node *stack_head)
{
    int i;
    s_node  *temp;
    
    i = 0;
    temp = stack_head;
    while (temp)
    {
        printf("Node %d is %d\n", i, temp->value);
        i++;
        temp = temp->next;
    }
}

void    free_stack(s_node *stack_head)
{
    if (!stack_head)
        return ;
    free_stack(stack_head->next);
    free(stack_head);
}