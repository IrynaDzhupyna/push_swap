/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:03:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 18:32:32 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node  *smallest_node(s_node *stack_head)
{
    s_node  *min;
    s_node  *current;

    current = stack_head;
    min = stack_head;
    printf("\nBEGGINING SMALLEST NODE  IN SMALLEST %d\n", min->value);
    while (current)
    {
        if (current->value < min->value)
            min = current;
        current = current->next;
    }
    printf("\nSMALLEST NODE IN SMALLEST %d\n", min->value);
    return (min);
}

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


//add index to smallest_node()
//if index <= 2 ra if index > 2 rra
void    sort_four(s_node **stack_head_a, s_node **stack_head_b)
{
    s_node  *min_node;
    int i;

    i = 0;
    min_node = smallest_node(*stack_head_a);
    printf("SMALLEST NODE in SORT_FOUR %d\n", min_node->value);
    while (*stack_head_a != min_node)
    {
        rotate(stack_head_a);
        printf("+\n");
    }
    push(stack_head_b, stack_head_a);
    printf("\nSTACK A AFTER PUSH:\n");
    print_stack(*stack_head_a);
    printf("\nSTACK B AFTER PUSH:\n");
    print_stack(*stack_head_b);
    sort_three(stack_head_a);
    
    printf("STACK A AFTER SORT\n");
    print_stack(*stack_head_a);
    push(stack_head_a, stack_head_b);
    
    /*printf("\nSTACK A:\n");
    print_stack(*stack_head_a);
    printf("\nSTACK B:\n");
    print_stack(*stack_head_b);*/
    /*if (!stack_is_sorted(*stack_head_a))
    {
        push(stack_head_a, stack_head_b);
        sort_three(stack_head_a);
        push(stack_head_b, stack_head_a);  
    }*/
}

void    small_sort(s_node **stack_head_a, s_node **stack_head_b, int size)
{
    if (size < 2)
        return ;
    else if (size == 2)
        swap(stack_head_a);
    else if (size == 3)
        sort_three(stack_head_a);
    else if (size == 4)
        sort_four(stack_head_a, stack_head_b);
    /*else if (size == 5)
        sort_five(&stack_head_a, &stack_head_b);*/

    /*printf("\nSTACK A:\n");
    print_stack(*stack_head_a);
    printf("\nSTACK B:\n");
    print_stack(*stack_head_b);*/
}