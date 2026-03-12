/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:36 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/12 17:32:49 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int index;
    struct node *next;
    struct node *prev;
}   s_node;

int parse_args(int argc, char **argv, s_node **stack_a);
int get_int(char *s, int *n);
int check_duplicates(s_node *stack_head, int *num);
s_node  *new_node_create(int *num, int *index);
void    node_add_back(s_node **stack, s_node *new_node);
char	**ft_split(char const *s, char c);
void    swap(s_node **stack_head);

#endif