/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:54:56 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 12:22:03 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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