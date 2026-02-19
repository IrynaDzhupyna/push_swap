/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:53:43 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/19 15:45:16 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//check input - arg
//	is all int
//	is all valid int
//	no duplicates

// my atoi doesn't cover INT_MIN INT_MAX +
int     ft_atoi(const char *nptr)
{
        int     i;
        int     sign;
        int     nbr;

        i = 0;
        sign = 1;
        nbr = 0;
        while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == 32))
                i++;
        if (nptr[i] == '+' || nptr[i] == '-')
        {
                if (nptr[i] == '-')
                        sign = -1;
                i++;
        }
        while (48 <= nptr[i] && nptr[i] <= 57)
        {
                nbr = nbr * 10 + (nptr[i] - 48);
                i++;
        }
        return (nbr * sign);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc < 2)
		return (printf("Not enough arrguments\n"));
	n = ft_atoi(argv[1]);
	printf("%i\n", n);
}
