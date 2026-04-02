/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/02 12:59:20 by idzhup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = set_indexes(*stack_a);
	if (stack_size <= 5)
		small_sort(stack_a, stack_b, stack_size);
	else
		big_sort(stack_a, stack_b, stack_size);
}

static char	**init_args(int argc, char **argv, int *is_split)
{
	char	**arr;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (NULL);
		*is_split = 1;
	}
	else
	{
		arr = argv + 1;
		*is_split = 0;
	}
	return (arr);
}

static void	cleanup(t_node *a, t_node *b, char **arr, int is_split)
{
	if (is_split)
		free_split(arr);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr;
	int		is_split;

	stack_a = NULL;
	stack_b = NULL;
	arr = init_args(argc, argv, &is_split);
	if (!arr)
		return (error_exit("Error\n"));
	if (!parse_args(argc, arr, &stack_a))
	{
		cleanup(stack_a, stack_b, arr, is_split);
		return (error_exit("Error\n"));
	}
	if (!stack_is_sorted(stack_a))
		choose_sorting(&stack_a, &stack_b);
	cleanup(stack_a, stack_b, arr, is_split);
	return (0);
}


/*int	main(int argc, char **argv)
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
		return (free_stack(stack_a), error_exit("Error\n"));
	if (!(stack_is_sorted(stack_a)))
		choose_sorting(&stack_a, &stack_b);
	if (argc == 2)
		free(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}*/