/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:47:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/12 17:42:00 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(s_node **stack)
{
    s_node  *first;
    s_node  *second;
    s_node  *third;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    first->next = second;
    second->next = third;

    
}