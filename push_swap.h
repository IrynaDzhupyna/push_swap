/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:36 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/31 13:25:40 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int value;
    int index;
    struct node *next;
}   s_node;

int     parse_args(int argc, char **argv, s_node **stack_a);
int     get_int(char *s, int *n);
int     check_duplicates(s_node *stack_head, int *num);
char    **ft_split(char const *s, char c);

s_node  *new_node_create(int *num);
void    node_add_back(s_node **stack, s_node *new_node);
//int     node_counter(s_node *stack_head);
int bits_counter(int max_index);
s_node  *smallest_node(s_node *stack_head);
int     get_node_position(s_node *stack_head, s_node *target_node);
void    find_push_smallest(s_node **stack_head_a, s_node **stack_head_b);

//int     stack_isEmpty(s_node *top);
int     stack_is_sorted(s_node *stack_head);
void    free_stack(s_node *stack_head);
int    set_indexes(s_node *stack_head);

void    small_sort(s_node **stack_head_a, s_node **stack_head_b, int size);
void    big_sort(s_node **stack_head_a, s_node **stack_head_b, int size);
int bits_counter(int max_index);

void    sort_three(s_node **stack_head__a);
void    sort_four(s_node **stack_head_a, s_node **stack_head_b);
void	sort_five(s_node **stack_head_a, s_node **stack_head_b);

//swap
void    swap(s_node **stack_head);
void    sa(s_node **stack_head_a);
void    sb(s_node **stack_head_b);
void    ss(s_node **stack_head_a, s_node **stack_head_b);

//rotate
void    rotate(s_node **stack_head);
void    ra(s_node **stack_head_a);
void    rb(s_node **stack_head_b);
void    rr(s_node **stack_head_a, s_node **stack_head_b);

//reverse rotate
void    reverse_rotate(s_node **stack_head);
void    rra(s_node **stack_head_a);
void    rrb(s_node **stack_head_b);
void    rrr(s_node **stack_head_a, s_node **stack_head_b);

//push
void    push(s_node **dst_head, s_node **src_head);
void    pa(s_node **stack_head_a, s_node **stack_head_b);
void    pb(s_node **stack_head_a, s_node **stack_head_b);

int     error_exit(char *s);
void    print_stack(s_node *stack_head);
int     ft_strlen(const char *s);

#endif