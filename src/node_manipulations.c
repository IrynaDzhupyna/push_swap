/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:05:42 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 21:24:11 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node_create(int *num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = *num;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	node_add_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

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

int	get_node_position(t_node *stack_head, t_node *target_node)
{
	int	i;

	i = 0;
	while (stack_head)
	{
		if (stack_head == target_node)
			return (i);
		stack_head = stack_head->next;
		i++;
	}
	return (-1);
}

void	node_indexation(t_node *new_node, t_node *stack_head)
{
	t_node	*temp;
	int		i;

	if (!stack_head)
		return ;
	temp = stack_head;
	i = 1;
	while (temp->next)
	{
		if (temp->value > new_node->value)
		{
			temp->index = i;
			i++;
			temp = temp->next;
		}
	}
}
