/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:40:19 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/04 14:02:52 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ERROR == return(0)
//OK == return (1)
int	parse_int_check(const char *s, int *int_out)
{
	int	i;
	int	sign;
	long	num;
	long	limit;
	long	digit;

	i = 0;
	sign = 1;
	num = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
			i++;
		else if ((s[i] == '+' || s[i] == '-') && ('0' <= s[i + 1] && s[i + 1] <= '9'))
		{
				if (s[i] == '-')
					sign = -1;
				i++;
		}
		else if ('0' <= s[i] && s[i] <= '9')
		{
			if (sign == -1)
				limit = 2147483648L;
			else
				limit = 2147483647L;
			while ('0' <= s[i] && s[i] <= '9')
			{
				digit = s[i] - 48;
				if (num > (limit - digit) / 10)
					return (0);
				num = num * 10 + (s[i] - 48);
				i++;
			}
		}
		else
			return (0);
	}
	num = num * sign;
	*int_out = num;
	return (1);
}
/*
#include <stdio.h>

int	main(int argc, char ** argv)
{
	int	i;
	int	value;

	if (argc < 2)
		return (printf("Not enough arguments"), 1);
	i = 1;
	while (argv[i])
	{
		if (!(parse_int_check(argv[i], &value)))
			return (printf("Invalid argument"));
		else
		{
			printf("%i\n", value);
			i++;
		}
	}
	return (0);
}*/
