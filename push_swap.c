/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:29:29 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 16:44:00 by irdzhupy         ###   ########.fr       */
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
	long	num;

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
			num = ft_atoi_strict(argv[i]);
			if (num > INT_MIN || num < INT_MIN)
				return (printf("Not an int"), 2);
			printf("%li\n", num);
			i++;
		}
	}
	//fill the stack
	return (0);
}
