/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/23 16:16:40 by irdzhupy         ###   ########.fr       */
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
    printf("Stack Beginning\n");
    print_stack(stack_a);
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
        
    printf("Stack Un - Sorted is \n");
    print_stack(stack_a);
    
    stack_size = node_counter(stack_a);
    printf("N of Nodes is: %i\n", stack_size);
    if (stack_size <= 5)
    {
        small_sort(stack_a, stack_b, stack_size);
    }   
    printf("\nFINAL STACK A IS:\n");
    print_stack(stack_a);       
    return (0);
}