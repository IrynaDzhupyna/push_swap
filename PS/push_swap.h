/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:03:48 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/06 19:47:04 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct StackNode
{
    int value;
    int index;
    struct StackNode	*next;
}	node;

node	*ps_new_node(int *value, int index);
void	ps_node_add_back(node **stack, node *new_node);

#endif