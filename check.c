/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:40:19 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 17:59:08 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ERROR == return(0)
//OK == return (1)
int	parse_int_check(const char *s, int *int_out)
{
	int	sign;
	long	num;

	sign = 1;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
			i++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if ('0' <= s[i + 1] && s[i + 1] == '9')
			{
				if (s[i] == '-')
					sign = -1;
				i++;
			}
			else
				return (0);
		}
		else if ('0' <= s[i] && s[i] <= '9')
		{
			num = 0;
			while ('0' <= s[i] && s[i] <= '9')
			{
				if (INT_MIN < num && num < INT_MAX)
					num = num * 10 + s[i];
				else
					return (0);
				i++;
			}
		}
		else
			return (0);
	}
	if (s[i] != '\0')
		return (0);
	*int_out = num;
	return (1);
}
