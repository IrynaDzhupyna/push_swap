/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:10 by irdzhupy          #+#    #+#             */
/*   Updated: 2025/12/17 14:12:28 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_counter(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		num++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free_split(char **arr, size_t filled)
{
	while (filled > 0)
		free(arr[filled--]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	arr = malloc((ft_counter(s, c) + 1) * sizeof(*arr));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_counter(s, c))
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s + i, c);
		arr[j] = ft_substr(s, i, len);
		if (!arr[j])
			return (ft_free_split(arr, j), NULL);
		i = i + len;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
