/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/12 17:35:31 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    s_node  *stack_a;
    s_node  *stack_b;
    s_node  *temp;
    char    **arr;
    int i;
    
    i = 0;
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (printf("argc < 2\n"));
    else if (argc == 2)
        arr = ft_split(argv[1], ' ');
    else
        arr = argv;
    //maybe better to do parse_args separately because there will be 2 diff roads. argc==2 free(arr)
    if (!parse_args(argc, arr, &stack_a))
        return (printf("Problem in parse_args\n"));
    /*temp = stack_a;
    while (temp)
    {
        printf("Node %d is %d\n", i, temp->value);
        i++;
        temp = temp->next;
    }*/
    printf("LETS SWAP\n");
    swap(&stack_a);
    temp = stack_a;
    while (temp)
    {
        printf("Node %d is %d\n", i, temp->value);
        i++;
        temp = temp->next;
    }
    // Free the entire list, not just the head
    //if (argc == 2)
    //  free(arr);
    return (0);
}