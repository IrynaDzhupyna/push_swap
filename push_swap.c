/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:29:29 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/04 14:08:29 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	l_node	*list;
	l_node	*new;
	char	**s_temp;
	int	i;
	int	num;
	int	value;

	list = NULL;
	new = NULL;
	s_temp = NULL;
	i = 1;
	if (argc < 2)
		return (printf("Not enough arguments"), 1);
	else if (argc == 2)
		s_temp = ft_split(argv[1], ' ');
	else
	{
		while (argv[i])
		{
			if (!(parse_int_check(argv[i], &value)))
				return (printf("Invalid argument"));
			else
			{
				num = parse_int_check(argv[i], &value);
				printf("%i\n", num);
				i++;
			}
		}
	}
	//fill the stack
	return (0);
}
