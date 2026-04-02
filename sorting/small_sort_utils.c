/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 18:25:54 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_high_first(t_node **stack, t_node *a, t_node *b, t_node *c)
{
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		sa(stack);
	else if (a->value > b->value && b->value > c->value)
	{
		sa(stack);
		rra(stack);
	}
	else if (a->value > b->value && b->value < c->value && a->value > c->value)
		ra(stack);
}

void	sort_three_low_first(t_node **stack, t_node *a, t_node *b, t_node *c)
{
	if (a->value < b->value && b->value > c->value && a->value < c->value)
	{
		sa(stack);
		ra(stack);
	}
	else if (a->value < b->value && b->value > c->value && a->value > c->value)
		rra(stack);
}

void	sort_three(t_node **stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = *stack;
	b = a->next;
	c = b->next;
	if (a->value < b->value && b->value < c->value)
		return ;
	if (a->value > b->value)
		sort_three_high_first(stack, a, b, c);
	else
		sort_three_low_first(stack, a, b, c);
}

void	sort_four(t_node **stack_head_a, t_node **stack_head_b)
{
	find_push_smallest(stack_head_a, stack_head_b);
	sort_three(stack_head_a);
	pa(stack_head_a, stack_head_b);
}

void	sort_five(t_node **stack_head_a, t_node **stack_head_b)
{
	find_push_smallest(stack_head_a, stack_head_b);
	find_push_smallest(stack_head_a, stack_head_b);
	sort_three(stack_head_a);
	pa(stack_head_a, stack_head_b);
	pa(stack_head_a, stack_head_b);
}
