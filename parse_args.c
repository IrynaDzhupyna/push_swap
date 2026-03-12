/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:08:57 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/12 13:09:12 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_int(char *s, int *n)
{
    int i;
    int sign;
    long long   num;
    long long   limit;

    if (!s || !n)
        return (printf("No *s or *n\n"), 0);
    i = 0;
    sign = 1;
    num = 0;
    while ((9 <= s[i] && s[i] <= 13) || s[i] == 32 || s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    if (sign == -1)
        limit = 2147483648;
    else
        limit = 2147483647;
    while (48 <= s[i] && s[i] <= 57)
    {
        if (num > (limit - (s[i] - 48)) / 10)
            return (0);
        num = num * 10 + (s[i] - 48);
        i++;
    }
    if (s[i] != '\0')
        return (0);
    *n = sign * num;
    return (1);
}

int check_duplicates(s_node *stack_head,int *num)
{
    s_node  *current;
    
    if (!num)
        return (0);
    if (!stack_head)
        return (1);
    current = stack_head;
    while (current)
    {
        dprintf(1, "Current value is %i and next num is %i\n", current->value, *num);
        if (current->value == *num)
            return (printf("Duplication found\n"), 0);
        printf("NO DUPLICATES YET\n");
        current = current->next;
    }
    return (1);
}

int parse_args(int argc, char **arr, s_node **stack_a)
{
    int i;
    int num;
    int index;
    s_node  *node;

    if (argc == 2)
        i = 0;
    else
        i = 1;
    *stack_a = NULL;
    index = 0;
    while (arr[i])
    {
        printf("i is %d\n", i);
        if (get_int(arr[i], &num) == 0)
            return (printf("Problem in get_int\n"), 0);
        if (check_duplicates(*stack_a, &num) == 0)
            return (printf("Problem in check_duplicates()\n"), 0);
        node = new_node_create(&num, &index);
        node_add_back(stack_a, node);
        i++;
        index++;
        printf("num is %d\n", num);
    }
    return (printf("Duplicates not found\n"), 1);
}