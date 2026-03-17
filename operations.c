/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:47:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/17 17:54:49 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a) || sb (swap b)
    Swap the first 2 elements at the top of stack X.
    Do nothing if there is only one element or none.
*/
void    swap(s_node **stack_head)
{
    s_node  *first;
    s_node  *second;
    
    if (!stack_head || !*stack_head || !(*stack_head)->next)
        return ;
    first = *stack_head;
    second = (*stack_head)->next;
    first->next = second->next;
    second->next = first;
    *stack_head = second;
    print(*stack_head);
}

/*
pa (push a) || pb (push b)
    Take the first element at the top of X and put it at the top of Y
    Do nothing if b is empty
*/
void    push(s_node **dst_head, s_node **src_head)
{
    s_node  *temp;
    s_node  *new_head;
    
    if (!src_head || !*src_head || !dst_head)
        return ;
    temp = *src_head;
    new_head = (*src_head)->next;
    temp->next = *dst_head;
    *dst_head = temp;
    *src_head = new_head;
    printf("\nSTACK_B IS NOW:\n");
    print(*dst_head);
    printf("\nSTACK_A IS NOW:\n");
    print(*src_head);
}

/*
ra (rotate a) || rb(rotate b)
    Shift up all elements of stack a by 1.
    The first element becomes the last one.
*/
void    rotate(s_node **stack_head)
{
    s_node    *temp;
    s_node    *new_head;
    s_node    *current;

    if (!stack_head || !*stack_head || (*stack_head)->next == NULL)
        return ;
    temp = *stack_head;
    new_head = (*stack_head)->next;
    current = *stack_head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    *stack_head = new_head;
    print(*stack_head);
}

/*
rra (reverse rotate a)|| rrb (reverse rotate b)
    Shift down all elements of stack a by 1.
    The last element becomes the first one.
*/
void    reverse_rotate(s_node **stack_head)
{
    s_node    *current;
    s_node    *last;
    s_node    *new_head;

    current = *stack_head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    last = current;
    new_head = current->next;
    current->next = NULL;
    new_head->next = *stack_head;
    *stack_head = new_head;
    print(*stack_head);
}