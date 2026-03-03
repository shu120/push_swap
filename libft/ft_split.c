/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:50:59 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/25 22:44:23 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_all(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
}

static char	*word_dup(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*str;

	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	fill_words(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[j] = word_dup(s, start, i);
			if (!arr[j])
				return (free_all(arr, j), SIZE_MAX);
			j++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_count;
	size_t	last;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	last = fill_words(s, c, arr);
	if (last == SIZE_MAX)
		return (NULL);
	arr[last] = NULL;
	return (arr);
}
