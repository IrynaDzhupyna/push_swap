/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:54:56 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 17:37:52 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//unused
/*int     node_counter(t_node *stack_head)
{
    int i;
    t_node  *current;
    
    i = 0;
    current = stack_head;
    while (current)
    {
        current = current->next;
        i++;
    }
    return (i);
}*/

int  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}