/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:36:23 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 16:52:06 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>

typedef struct node
{
	int			number;
	struct node	*next;
}				l_node;

char			**ft_split(char const *s, char c);
int	ft_atoi_strict(const char *nptr);
#endif
