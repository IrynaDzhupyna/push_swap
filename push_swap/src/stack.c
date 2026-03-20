/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:57:49 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/20 17:28:59 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return 1 if sorted
// return 0 if not
int     stack_is_sorted(s_node *stack_head)
{
    //go though all nodes and check if node->value < node->next->value
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
