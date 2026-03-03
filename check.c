/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:40:19 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/03 18:24:43 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ERROR == return(0)
//OK == return (1)
int	parse_int_check(const char *s, int *int_out)
{
	int	i;
	int	sign;
	long	num;
	long	limits;

	i = 0;
	sign = 1;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
			i++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if ('0' <= s[i + 1] && s[i + 1] <= '9')
			{
				if (s[i] == '-')
					sign = -1;
				i++;
			}
			else
				return (0);
		}
		//before reading digits we need to check limits
		//L means this num is long not int, 
		if (sign == -1)
			limits = -2147483648L;
		else
			limits = 2147483647L;
		else if ('0' <= s[i] && s[i] <= '9')
		{
			num = 0;
			while ('0' <= s[i] && s[i] <= '9')
			{
				if (INT_MIN < (num * 10 + (s[i] - '0')) && (num * 10 + (s[i] - '0')) < INT_MAX)
					num = num * 10 + (s[i] - '0');
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
