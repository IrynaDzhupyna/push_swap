/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:08:57 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 17:30:38 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_int(char *s, int *n)
{
	int			i;
	int			sign;
	long long	num;
	long long	limit;

	i = 0;
	sign = 1;
	num = 0;
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!(48 <= s[i] && s[i] <= 57))
		return (0);
	if (sign == -1)
		limit = 2147483648;
	else
		limit = 2147483647;
	while (48 <= s[i] && s[i] <= 57)
	{
		if (num > (limit - (s[i] - 48)) / 10)
			return (0);
		num = num * 10 + (s[i++] - 48);
	}
	if (s[i] != '\0')
		return (0);
	*n = sign * num;
	return (1);
}

int	check_duplicates(t_node *stack_head, int *num)
{
	t_node	*current;

	if (!num)
		return (0);
	if (!stack_head)
		return (1);
	current = stack_head;
	while (current)
	{
		if (current->value == *num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	parse_args(int argc, char **arr, t_node **stack_a)
{
	int		i;
	int		num;
	t_node	*node;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	*stack_a = NULL;
	while (arr[i])
	{
		if (get_int(arr[i], &num) == 0)
			return (0);
		if (check_duplicates(*stack_a, &num) == 0)
			return (0);
		node = new_node_create(&num);
		node_add_back(stack_a, node);
		i++;
	}
	return (1);
}
