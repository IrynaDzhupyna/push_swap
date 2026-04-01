/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:11:34 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/04/01 21:29:19 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	copy;
	size_t	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		copy = 0;
	else if (len > s_len - start)
		copy = s_len - start;
	else
		copy = len;
	new = (char *)malloc(copy + 1);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (j < copy)
	{
		new[j] = s[start + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

static size_t	ft_counter(char const *s, char c)
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

	if (!s || !*s)
		return (NULL);
	arr = malloc((ft_counter(s, c) + 1) * sizeof(*arr));
	if (!arr)
		return (free(arr), NULL);
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
