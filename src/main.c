/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/24 14:55:27 by irdzhupy         ###   ########.fr       */
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
    int     stack_size;
    
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
    {
        small_sort(&stack_a, &stack_b, stack_size);
    }
    else
        big_sort(&stack_a, &stack_b);
    printf("\nFINAL STACK A IS:\n");
    print_stack(stack_a);
    printf("\nFINAL STACK B IS:\n");
    print_stack(stack_b);
    if (argc == 2)
        free(arr); 
    return (0);
}