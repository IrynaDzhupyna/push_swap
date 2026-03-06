/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:49:08 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/06 21:30:11 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    //stack_a is ** so have a ook at parse_args again after changing
    /**
     * task 1 : create int get int and test it with main
     * task 2 : create a dublicate checker and test it with empty stack
     * task 3 : create a new node 
     * task 4 : add new node to stack and print all stack in main 
     * task 5 : test dublicate after adding new nodes
     * task 6 : print again all stack and make sure it is correct
     * task 7 : split using space and take the list into a while loop that call parse args
     * task 8 : create RA rotate stack (HOWW??? Hint : pointer play)
     */
    node    *stack_a;
    node    *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    
    if (argc < 2)
        return (printf("Not enought arguments"), 1);
    if (!(parse_args(argc, argv, stack_a)))
        return (printf("Args are not valid"), 2);
    
    //print every node from stack_a
    
    free(stack_a);
    
    
}