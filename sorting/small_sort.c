/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 16:03:14 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_sort(s_node *stack_head_a, s_node *stack_head_b, int size)
{
    stack_head_b = NULL;
    if (size < 2)
        return ;
    else if (size == 2)
        swap(&stack_head_a);
    else if (size == 3)
        sort_three(&stack_head_a);
    else if (size == 4)
        sort_four(&stack_head_a, &stack_head_b);
    /*else if (size == 5)
        sort_five(&stack_head_a, &stack_head_b);*/
}

//delete print_stack
//doesn't work with some negative some positive
void    sort_three(s_node **stack_head)
{
    s_node  *first;
    s_node  *second;
    s_node  *third;

    first = *stack_head;
    second = first->next;
    third = second->next;
    
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
}

void    sort_four(s_node **stack_head_a, s_node **stack_head_b)
{
    s_node  *min_node;
   //s_node  *current;
    int i;

    i = 0;
    min_node = smallest_node(stack_head_a);
    while (*stack_head_a != min_node)
        rotate(stack_head_a);
    if (!stack_is_sorted(*stack_head_a))
    {
        push(stack_head_a, stack_head_b);
        sort_three(stack_head_a);
        push(stack_head_b, stack_head_a);  
    }
}