/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 21:26:43 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node  *smallest_node(s_node *stack_head, int *index_smallest)
{
    s_node  *min;
    s_node  *current;

    current = stack_head;
    min = stack_head;
    *index_smallest = 0;
    //printf("\nBEGGINING SMALLEST NODE  IN SMALLEST %d\n", min->value);
    while (current)
    {
        if (current->value < min->value)
            min = current;
        current = current->next;
        index_smallest++;
    }
    //printf("\nSMALLEST NODE IN SMALLEST %d\n", min->value);
    return (min);
}

//doesn't work with some negative some positive
/*void    sort_three(s_node **stack_head)
{
    s_node  *first;
    s_node  *second;
    s_node  *third;

    first = *stack_head;
    second = first->next;
    third = second->next;
    
    if (stack_is_sorted(*stack_head))
        return ;
        
    if ((first->value > second->value) && (first->value > third->value))
    {
        rotate(stack_head);
        if (!stack_is_sorted(*stack_head))
            swap(stack_head);
    }
    else if ((first->value < second->value) && (second->value > third->value))
    {
        reverse_rotate(stack_head);
        if (!stack_is_sorted(*stack_head))
            swap(stack_head);
    }
    else
        swap(stack_head);
}*/

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

    min_node = smallest_node(*stack_head_a, &index_smallest);
    printf("INDEX OF SMALLEST IS %i\n", index_smallest);
    while (*stack_head_a != min_node)
    {
        rotate(stack_head_a);
        printf("+\n");
    }
    push(stack_head_b, stack_head_a);
    sort_three(stack_head_a);
    push(stack_head_a, stack_head_b);
}

void	sort_five(s_node **stack_head_a, s_node **stack_head_b)
{
	s_node	*min_node;
	int		index_smallest;

	min_node = smallest_node(*stack_head_a, &index_smallest);
	while (*stack_head_a != min_node)
	{
		if (index_smallest <= 2)
			rotate(stack_head_a);
		else
			reverse_rotate(stack_head_a);
	}
	push(stack_head_b, stack_head_a);
	min_node = smallest_node(*stack_head_a, &index_smallest);
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
    /*else if (size == 5)
        sort_five(&stack_head_a, &stack_head_b);*/

    /*printf("\nSTACK A:\n");
    print_stack(*stack_head_a);
    printf("\nSTACK B:\n");
    print_stack(*stack_head_b);*/
}