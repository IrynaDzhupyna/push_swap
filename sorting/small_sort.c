/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 14:09:06 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_three(s_node **stack_head)
{
	s_node	*first;
	s_node	*second;
	s_node	*third;

	if (!stack_head || !*stack_head || !(*stack_head)->next || !(*stack_head)->next->next)
		return ;
	first = *stack_head;
	second = first->next;
	third = second->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	if (first->value > second->value && second->value < third->value && first->value < third->value)
		swap(stack_head);
	else if (first->value > second->value && second->value > third->value)
	{ 
        swap(stack_head);
        reverse_rotate(stack_head);
    }
	else if (first->value > second->value && second->value < third->value && first->value > third->value)
		rotate(stack_head);
	else if (first->value < second->value && second->value > third->value && first->value < third->value)
	{ 
        swap(stack_head);
        rotate(stack_head);
    }
	else
		reverse_rotate(stack_head);
}

//add index to smallest_node()
//if index <= 2 ra if index > 2 rra
void    sort_four(s_node **stack_head_a, s_node **stack_head_b)
{
    s_node  *min_node;
    int index_smallest;

    min_node = smallest_node(*stack_head_a);
    index_smallest = get_node_position(*stack_head_a, min_node);
    printf("SMALLEST FIRST INDEX is %d\n", index_smallest);
    while (*stack_head_a != min_node)
    {
        if (index_smallest <= 2)
        {
            rotate(stack_head_a);
            printf("\n+++\n");
        }
        else
        {
            reverse_rotate(stack_head_a);
            printf("\n---n");
        }
    }
    push(stack_head_b, stack_head_a);
    sort_three(stack_head_a);
    push(stack_head_a, stack_head_b);
}

void	sort_five(s_node **stack_head_a, s_node **stack_head_b)
{
	s_node	*min_node;
	int		index_smallest;

	min_node = smallest_node(*stack_head_a);
    index_smallest = get_node_position(*stack_head_a, min_node);
    printf("SMALLEST FIRST INDEX is %d\n", index_smallest);
    //the same as sort_four
	while (*stack_head_a != min_node)
	{
		if (index_smallest <= 2)
			rotate(stack_head_a);
		else
			reverse_rotate(stack_head_a);
        printf("\n+\n");
	}
	push(stack_head_b, stack_head_a);
    
	min_node = smallest_node(*stack_head_a);
    index_smallest = get_node_position(*stack_head_a, min_node);
    printf("SMALLEST FIRST INDEX is %d\n", index_smallest);
	while (*stack_head_a != min_node)
	{
		if (index_smallest <= 1)
			rotate(stack_head_a);
		else
			reverse_rotate(stack_head_a);
	}
	push(stack_head_b, stack_head_a);
	sort_three(stack_head_a);
	push(stack_head_a, stack_head_b);
	push(stack_head_a, stack_head_b);
}

void    small_sort(s_node **stack_head_a, s_node **stack_head_b, int size)
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
}