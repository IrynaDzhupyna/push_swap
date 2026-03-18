/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:36 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/18 10:47:03 by irdzhupy         ###   ########.fr       */
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
char    **ft_split(char const *s, char c);

s_node  *new_node_create(int *num, int *index);
void    node_add_back(s_node **stack, s_node *new_node);

int     isEmpty(s_node *top);

void    swap(s_node **stack_head);
void    push(s_node **dst_head, s_node **src_head);
void    rotate(s_node **stack_head);
void    reverse_rotate(s_node **stack_head);

int     error_exit(char *s);
void    print_list(s_node *stack_head);
int     node_counter(s_node *stack_head);
#endif