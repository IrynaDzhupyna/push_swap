/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:36:50 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 15:32:02 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gets a str
//goes through stri and checks if it is valid int
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

int	input_check(const char *s)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		else if (!('0' <= s[i] && s[i] <= '9'))
			return (0);

		while ('0' <= s[i] && s[i] <= '9')
		{
			num = (num * 10) + (s[i] + 48);
			i++;
		}
	}
	if (INT_MIN < num &&  num > INT_MAX)
		return (0);
	return (1);
}

#include <stdio.h>

int	main(void)
{
	int	out;
	const char *s = "-2147483650";

	out = input_check(s);
	if (out == 0)
		return (printf("not valid"));
	return (printf("valid"));
}
