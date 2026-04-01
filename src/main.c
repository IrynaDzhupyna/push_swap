/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:40:15 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 18:40:32 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_exit(char *s)
{
    write(2, s, ft_strlen(s));
    return (1);
}

static int	str_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr;
	int		stack_size;

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
		free_stack(stack_a);
		return (error_exit("Error\n"));
	}
	if (!(stack_is_sorted(stack_a)))
	{
		stack_size = set_indexes(stack_a);
		if (stack_size <= 5)
			small_sort(&stack_a, &stack_b, stack_size);
		else
			big_sort(&stack_a, &stack_b, stack_size);
	}
	/*printf("\nSTACK_A\n");
	print_stack(stack_a);
	printf("\nSTACK B\n");
	print_stack(stack_b);*/
	free_stack(stack_a);
	free_stack(stack_b);
	if (argc == 2)
		free(arr);
	return (0);
}

