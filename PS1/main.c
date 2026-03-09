/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/09 17:08:05 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int index;
    struct node *next;
}   s_node;

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

s_node  *new_node_create(int *num, int index)
{
    s_node  *new_node;
    
    new_node = malloc(sizeof(s_node));
    if (!new_node)
        return (NULL);
    new_node->value = *num;
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}

void    node_add_back(s_node **stack, s_node *new_node)
{
    s_node  *temp;

    if (!stack || !new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
        
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

int check_duplicates(s_node *stack, int *num, int *index)
{
    s_node  *current;
    
    if (!num)
        return (0);
    if (!stack)
        return (1);
    current = stack;
    while (current)
    {
        dprintf(1, "Value is %i and num is %i\n", current->value, *num);
        if (current->value == *num)
            return (printf("Duplication found\n"), 0);
        printf("NO DUPLICATES YET\n");
        current = current->next;
        // dprintf(1, "Current %p, next %p\n", current, current->next);
    }
    return (1);
}

int parse_args(int argc, char **argv, s_node *stack_a)
{
    int i;
    int num;
    int index;
    s_node  *node;

    i = 1;
    stack_a = NULL;
    index = 0;
    while (i < argc)
    {
        if (get_int(argv[i], &num) == 0)
            return (printf("Problem in get_int\n"), 0);
        printf("GETINT RAN\n");
        if (check_duplicates(stack_a, &num, &index) == 0)
            return (printf("Problem in check_duplicates()\n"), 0);
        printf("CHECK DUP RAN\n");
        node = new_node_create(&num, index);
        node_add_back(&stack_a, node);
        i++;
        printf("i is %d\n", i);
        printf("num is %d\n", num);
    }
    return (printf("Duplicates not found"), 1);
}

int main(int argc, char **argv)
{
    s_node  *stack_a;
    
    if (argc < 2)
        return (printf("argc < 2"));
    if (!parse_args(argc, argv, stack_a))
        return (printf("Problem in parse_args"));
    return (printf("All good"), 0);
}