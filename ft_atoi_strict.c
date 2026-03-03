/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:02:05 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 17:40:06 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//i_out the converted int to return
//return (0) if ERROR
//return (1) if OK
int	ft_atoi_strict(const char *nptr, int *i_out)
{
	int	i;
	int	sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!nptr || !*nptr)
		return (0);
	while (nptr[i])
	{
		while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == 32))
			i++;
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			if (nptr[i] == '-')
				sign = -1;
			i++;
		}
		else if (48 <= nptr[i] && nptr[i] <= 57)
		{
			while (48 <= nptr[i] && nptr[i] <= 57)
			{
				nbr = nbr * 10 + (nptr[i] - 48);
				i++;
			}
			if (nptr[i] != '\0')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
