/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:29:29 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/02 15:58:31 by irdzhupy         ###   ########.fr       */
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
	l_node	*new;
	char	**s_temp;
	int	i;
	int	num;

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
			num = ft_atoi(argv[i]);
			//atoi_strict check in utils
			new = ft_lstnew(i);



	//fill the stack
	//atoi with int check
}
