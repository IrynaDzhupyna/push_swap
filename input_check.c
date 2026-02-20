/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:10:46 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/20 11:26:50 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
