/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:49:37 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/24 18:42:06 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	rem;
	char	*sub;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	rem = ft_strlen (s + start);
	if (rem < len)
		len = rem;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	count = 0;
	while (count < len)
	{
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = '\0';
	return (sub);
}
