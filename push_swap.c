/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:29:29 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/02 13:42:47 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*typedef struct node
{
	int			number;
	struct node	*next;
}				l_node;
*/
int	main(int argc, char **argv)
{
	l_node	*list;
	char	**s_temp;

	list = NULL;
	s_temp = NULL;
	if (argc < 2)
		return (printf("Not enough arguments"), 1);
	else if (argc == 2)
		s_temp = ft_split(argv[1], ' ');
	while (*s_temp)
		printf("%s\n", *s_temp++);
	//fill the stack
	//atoi with int check
}
