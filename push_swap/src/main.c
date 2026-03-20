/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/20 14:24:20 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check error messages before submitting
//if argc == 2 - free(arr) 
static int  str_only_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    s_node  *stack_a;
    s_node  *stack_b;
    char    **arr;
    int     i;
    int     stack_size;
    
    i = 0;
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2 || str_only_spaces(argv[1]))
        return (error_exit("Not enough arguments\n"));
    else if (argc == 2)
        arr = ft_split(argv[1], ' ');   
    else
        arr = argv;
    if (!parse_args(argc, arr, &stack_a))
        return (error_exit("Problem in parse_args\n"));
    if (stack_is_sorted(stack_a))
        return (free_stack(stack_a), 0);
    stack_size = node_counter(stack_a);
    if (stack_size <= 5)
        small_sort(stack_a, stack_b, stack_size);
            
/*
    printf("\nSTACK_A BEFORE:\n");
    print_list(stack_a);
    
    printf("\nSTACK_A SWAPED\n");
    swap(&stack_a);
    
    printf("\nPUSH FROM A -> B");
    push(&stack_b, &stack_a);

    printf("\nROTATE STACK_A\n");
    rotate(&stack_a);

    printf("\nREVERSE ROTATE STACK_A\n");
    reverse_rotate(&stack_a);*/
    return (0);
}