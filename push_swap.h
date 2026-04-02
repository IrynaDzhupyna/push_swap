/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:50:36 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 10:21:45 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}				t_node;

int				parse_args(int argc, char **argv, t_node **stack_a);
int				get_int(char *s, int *n);
int				check_duplicates(t_node *stack_head, int *num);
char			**ft_split(char const *s, char c);

t_node			*new_node_create(int *num);
void			node_add_back(t_node **stack, t_node *new_node);
int				bits_counter(int max_index);
t_node			*smallest_node(t_node *stack_head);
int				get_node_position(t_node *stack_head, t_node *target_node);
void			find_push_smallest(t_node **stack_head_a,
					t_node **stack_head_b);

// int     stack_isEmpty(s_node *top);
int				stack_is_sorted(t_node *stack_head);
void			free_stack(t_node *stack_head);
int				set_indexes(t_node *stack_head);

void			sorting(t_node **stack_a, t_node **stack_b);
void			small_sort(t_node **stack_head_a, t_node **stack_head_b,
					int size);
void			big_sort(t_node **stack_head_a, t_node **stack_head_b,
					int size);
int				bits_counter(int max_index);

void			sort_three(t_node **stack_head__a);
void			sort_four(t_node **stack_head_a, t_node **stack_head_b);
void			sort_five(t_node **stack_head_a, t_node **stack_head_b);

// swap
void			swap(t_node **stack_head);
void			sa(t_node **stack_head_a);
void			sb(t_node **stack_head_b);
void			ss(t_node **stack_head_a, t_node **stack_head_b);

// rotate
void			rotate(t_node **stack_head);
void			ra(t_node **stack_head_a);
void			rb(t_node **stack_head_b);
void			rr(t_node **stack_head_a, t_node **stack_head_b);

// reverse rotate
void			reverse_rotate(t_node **stack_head);
void			rra(t_node **stack_head_a);
void			rrb(t_node **stack_head_b);
void			rrr(t_node **stack_head_a, t_node **stack_head_b);

// push
void			push(t_node **dst_head, t_node **src_head);
void			pa(t_node **stack_head_a, t_node **stack_head_b);
void			pb(t_node **stack_head_a, t_node **stack_head_b);

int				error_exit(char *s);
int				ft_strlen(const char *s);
void			print_stack(t_node *stack_head);
#endif
