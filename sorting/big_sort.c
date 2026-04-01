/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:34:39 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 21:35:29 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits_counter(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

void	big_sort(t_node **stack_head_a, t_node **stack_head_b, int stack_size)
{
	int	max_index;
	int	bits_needed;
	int	num;
	int	i;
	int	j;

	max_index = stack_size - 1;
	bits_needed = bits_counter(max_index);
	i = 0;
	while (i < bits_needed)
	{
		j = 0;
		while (j < stack_size)
		{
			num = (*stack_head_a)->index;
			if (((num >> i) & 1) == 1)
				ra(stack_head_a);
			else
				pb(stack_head_a, stack_head_b);
			j++;
		}
		while (*stack_head_b)
			pa(stack_head_a, stack_head_b);
		i++;
	}
}
