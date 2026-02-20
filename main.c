/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:53:43 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/20 16:10:36 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//check input - arg
//	is all int
//	is all valid int
//	no duplicatesi
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strdup(const char *s)
{
        char    *d;
        size_t  i;

        i = 0;
        d = malloc(ft_strlen(s) + 1);
        if (d == NULL)
        {
                return (NULL);
        }
        while (s[i])
        {
                d[i] = s[i];
                i++;
        }
        d[i] = '\0';
        return (d);
}

int	is_valid_token(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[i][j] == 43 || argv[i][j] == 45 ||(8 <= argv[i][j] && argv[i][j] <= 57))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**stack_a;
	char	*stack_b;
	int	i;
	int	j;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	j = 0;
	if (argc < 2)
		return (printf("Not enough arrguments\n"), 1);
	while (argv[i])
	{
		if (!is_valid_token(&argv[i]))
			return (printf("Argument %i (%s) is invalid\n", i, argv[i]));
		else
		{
			printf("Argument %i (%s) is valid\n", i , argv[i]);
			//add argv[i] to stack_a[j]
			//stack_a[j] = ft_strdup(argv[i]);
			i++;
			//j++;
		}
	}
	/*j = 0;
	printf("Stack a is now filled with:\n");
	while (stack_a[j])
	{
		printf("%s\n", stack_a[j]);
		j++;
	}*/
}
