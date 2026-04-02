/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 11:28:41 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_push_smallest(t_node **stack_head_a, t_node **stack_head_b)
{
	t_node	*min_node;
	int		index_smallest;

	min_node = smallest_node(*stack_head_a);
	index_smallest = get_node_position(*stack_head_a, min_node);
	if (*stack_head_a == min_node)
		pb(stack_head_a, stack_head_b);
	else
	{
		while (*stack_head_a != min_node)
		{
			if (index_smallest <= 2)
				ra(stack_head_a);
			else
				rra(stack_head_a);
		}
		pb(stack_head_a, stack_head_b);
	}
}

//sort_tree team
#include "push_swap.h"

static void	sort_three_high_first(t_node **stack, t_node *a, t_node *b, t_node *c)
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

static void	sort_three_low_first(t_node **stack, t_node *a, t_node *b, t_node *c)
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

/*void	sort_three(t_node **stack)
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
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		sa(stack);
	else if (a->value > b->value && b->value > c->value)
	{
		sa(stack);
		rra(stack);
	}
	else if (a->value > b->value && b->value < c->value && a->value > c->value)
		ra(stack);
	else if (a->value < b->value && b->value > c->value && a->value < c->value)
	{
		sa(stack);
		ra(stack);
	}
	else if (a->value < b->value && b->value > c->value && a->value > c->value)
		rra(stack);
}*/

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

/*void    small_sort(s_node **stack_head_a, s_node **stack_head_b, int size)
{
	if (size < 2)
		return ;
	else if (size == 2)
	{
		if (!stack_is_sorted(*stack_head_a))
			swap(stack_head_a);
	}
	else if (size == 3)
	{
		if (!stack_is_sorted(*stack_head_a))
			sort_three(stack_head_a);
	}
	else if (size == 4)
	{
		if (!stack_is_sorted(*stack_head_a))
			sort_four(stack_head_a, stack_head_b);
	}
	else if (size == 5)
	{
		if (!stack_is_sorted(*stack_head_a))
			sort_five(stack_head_a, stack_head_b);
	}
}*/

void	small_sort(t_node **stack_head_a, t_node **stack_head_b, int size)
{
	if (size < 2)
		return ;
	else if (size == 2)
		sa(stack_head_a);
	else if (size == 3)
		sort_three(stack_head_a);
	else if (size == 4)
		sort_four(stack_head_a, stack_head_b);
	else if (size == 5)
		sort_five(stack_head_a, stack_head_b);
}
