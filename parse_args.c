/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:37:28 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/04 15:18:00 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_int_check(const char *s, int *int_out)
{
	int		i;
	int		sign;
	long	num;
	long	limit;

	i = 0;
	sign = 1;
	num = 0;
	if (!s || !*s)
		return (0);
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	if (!('0' <= s[i] && s[i] <= '9'))
		return (0);
	if (sign == -1)
		limit = 2147483648L;
	else
		limit = 2147483647L;

	while ('0' <= s[i] && s[i] <= '9')
	{
		if (num > (limit - (s[i] - 48)) / 10)
			return (0);
		num = num * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*int_out = num * sign;
	return (1);
}

int	parse_args(int argc, char **argv, int **arr, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
	{
		while (i < argc)
		{
			if (!parse_int_check(argv[i], &n))
				return (printf("Invalid argument"), 1);
			else
			{
				arr[j] = parse_int_check(argv[i], &n);
				i++;
				j++;
			}
		}
	}

}
