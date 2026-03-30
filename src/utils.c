/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:54:56 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/30 13:46:58 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//unused
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