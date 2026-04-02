/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 17:54:15 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(char *s)
{
	write(2, s, ft_strlen(s));
	return (1);
}

int	str_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	choose_sorting(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = set_indexes(*stack_a);
	if (stack_size <= 5)
		small_sort(stack_a, stack_b, stack_size);
	else
		big_sort(stack_a, stack_b, stack_size);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	else if (str_only_spaces(argv[1]))
		return (error_exit("Error\n"));
	else if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv;
	if (!parse_args(argc, arr, &stack_a))
	{
		if (argc == 2)
			free_split(arr);
		return (free_stack(stack_a), error_exit("Error\n"));
	}
	if (!(stack_is_sorted(stack_a)))
		choose_sorting(&stack_a, &stack_b);
	if (argc == 2)
		free_split(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
/*
#include "push_swap.h"

int	error_exit(char *s)
{
	write(2, s, ft_strlen(s));
	return (1);
}

int	str_only_spaces(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	choose_sorting(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = set_indexes(*stack_a);
	if (stack_size <= 5)
		small_sort(stack_a, stack_b, stack_size);
	else
		big_sort(stack_a, stack_b, stack_size);
}

static char	**get_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (str_only_spaces(argv[1]))
			return (NULL);
		return (ft_split(argv[1], ' '));
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	arr = get_args(argc, argv);
	if (!arr)
		return (error_exit("Error\n"));
	if (!parse_args(argc, arr, &stack_a))
	{
		if (argc == 2)
			free_split(arr);
		return (free_stack(stack_a), error_exit("Error\n"));
	}
	if (!stack_is_sorted(stack_a))
		choose_sorting(&stack_a, &stack_b);
	if (argc == 2)
		free_split(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}*/