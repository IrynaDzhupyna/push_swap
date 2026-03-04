/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:40:19 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/04 12:06:09 by irdzhupy         ###   ########.fr       */
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

		if (sign == -1)
			limits = -2147483648L;
		else
			limits = 2147483647L;

		while ('0' <= s[i] && s[i] <= '9' || s[i] != '\0')
		{
			if ((num * 10 + (s[i] - 48)) < limits)
			{
				num = num * 10 + (s[i] - 48);
				i++;
			}
			else
				return (0);
		}
	}
	if (s[i] != '\0')
		return (0);
	*int_out = num;
	return (1);
}
