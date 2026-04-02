/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:13:04 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 18:25:09 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
