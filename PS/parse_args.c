/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:03:14 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/06 21:19:12 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_int(const char *s, int *int_out)
{
	int		i;
	int		sign;
	long	num;
	long	limit;

	i = 0;
	sign = 1;
	num = 0;
	if (!s || !*s)
		return (0);
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
        i++;
	}
	if (!('0' <= s[i] && s[i] <= '9'))
		return (0);
	if (sign == -1)
		limit = 2147483648L;
	else
		limit = 2147483647L;

	while ('0' <= s[i] && s[i] <= '9')
	{
		if (num > (limit - (s[i] - 48)) / 10)
			return (0);
		num = num * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*int_out = num * sign;
	return (1);
}

//0 if fails
//1 on success
int check_dup(int *stack, int *num)
{
    node    *current;
    
    if (!stack)
        return (1);
    current = stack;
    while (current != NULL)
    {
        if (current->value == &num)
            return (0);
    }
    return (1);
}

void    ps_node_add_back(node **stack, node *new_node)
{
    node    *temp;

    if (!stack || !new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    temp = *stack;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

//read, validate, convert, store as node
int parse_args(int argc, char **argv, node *stack_a)
{
    int i;
    int j;
    int num;
    node    *current;

    i = 1;
    j = 0;
    while (argv[i])
    {
        //validate && convert
        if (get_int(argv[i], &num) == 0)
            return (NULL);
        if (check_dup(&stack_a, &num) == 0)
            return (NULL);
        //we got the num now store it in node
        current = ps_new_node(&num, j);
        ps_node_add_back(&stack_a, current);
    } 
    //read


    /*
    int i;
    int num;
    node    *stack_a;
    node    *node_a;
    
    *n = argc - 1;
    *arr = malloc(sizeof(int) * (*n));
    if (!*arr)
        return (0);
    i = 1;
    
    stack_a = NULL;
    while (argv[i])
    {
        node_a = ps_new_node(parse_int_check(argv[i]));
        node_a = ft_lstadd_back(&stack_a, argv[i]);
        if (!node_a)
            node_a->value = ft_lstnew(argv[i]);
        i++;
    }
    return (n);*/
}