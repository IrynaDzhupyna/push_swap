/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:54:56 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/18 10:47:11 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_list(s_node *stack_head)
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