/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/18 10:45:16 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    s_node  *stack_a;
    s_node  *stack_b;
    char    **arr;
    int i;
    
    i = 0;
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (error_exit("Not enough arguments\n"));
    else if (argc == 2)
        arr = ft_split(argv[1], ' ');
    else
        arr = argv;
    if (!parse_args(argc, arr, &stack_a))
        return (error_exit("Problem in parse_args\n"));

    printf("\nSTACK_A BEFORE:\n");
    print(stack_a);
    
    printf("\nSTACK_A SWAPED\n");
    swap(&stack_a);
    
    printf("\nPUSH FROM A -> B");
    push(&stack_b, &stack_a);

    printf("\nROTATE STACK_A\n");
    rotate(&stack_a);

    printf("\nREVERSE ROTATE STACK_A\n");
    reverse_rotate(&stack_a);
    return (0);
}