/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 21:31:46 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*smallest_node(t_node *stack_head)
{
	t_node	*min;
	t_node	*current;

	current = stack_head;
	min = stack_head;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

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

void	sort_three(t_node **stack_head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack_head || !*stack_head || !(*stack_head)->next
		|| !(*stack_head)->next->next)
		return ;
	first = *stack_head;
	second = first->next;
	third = second->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	if (first->value > second->value && second->value < third->value
		&& first->value < third->value)
		sa(stack_head);
	else if (first->value > second->value && second->value > third->value)
	{
		sa(stack_head);
		rra(stack_head);
	}
	else if (first->value > second->value && second->value < third->value
		&& first->value > third->value)
		ra(stack_head);
	else if (first->value < second->value && second->value > third->value
		&& first->value < third->value)
	{
		sa(stack_head);
		ra(stack_head);
	}
	else if (first->value < second->value && second->value > third->value
		&& first->value > third->value)
		rra(stack_head);
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
