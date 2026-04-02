static char	**init_args(int argc, char **argv, int *is_split)
{
	char	**arr;

	if (argc == 2)
	{
		if (str_only_spaces(argv[1]))
			return (NULL);
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