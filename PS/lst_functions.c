/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:26:38 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/06 21:15:23 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node    *ps_new_node(int *value, int index)
{
    node    *new_node;
    
    new_node = malloc(sizeof(node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}


//free list function?