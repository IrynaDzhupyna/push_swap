/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 09:29:12 by idzhup           ###   ########.fr       */
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
    /*
    else if (size == 4)
        sort_four(&stack_head_a, &stack_head_b);
    else if (size == 5)
        sort_five(&stack_head_a, &stack_head_b);*/
}

//DIDN`T USE THIS FUNCTION
//Not sure about this
s_node  biggest_node(s_node **stack_head)
{
    s_node  *current;
    s_node  *max;

    current = *stack_head;
    while (current->value > current->next->value)
        current = current->next;
    max = current;
    return (*max);
}

s_node  smallest_node(s_node **stack_head)
{
    s_node  *current;
    s_node  *min;

    current = *stack_head;
    while (current->value < current->next->value)
        current = current->next;
    min = current;
    return (*min);
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
        print_stack(*stack_head);
    }
    else if ((first->value < second->value) && (second->value > third->value))
    {
        reverse_rotate(stack_head);
        if (!stack_is_sorted(*stack_head))
            swap(stack_head);
        print_stack(*stack_head);
    }
    else
    {
        swap(stack_head);
        print_stack(*stack_head);   
    }
}

void    sort_four(s_node **stack_head)
{
    s_node  *min_node;

    min_node = smallest_node(stack_head);
    while (*stack_head != min_node)
        rotate(stack_head);
    push(stack_head, &stack_head_b);
    sort_three(stack_head);
    push(&stack_head_b, stack_head);
}

void    sort_five(s_node **stack_head)
{
    s_node  *min_node;

    min_node = smallest_node(stack_head);
    while (*stack_head != min_node)
        rotate(stack_head);
    push(stack_head, &stack_head_b);
    sort_four(stack_head);
    push(&stack_head_b, stack_head);
}

