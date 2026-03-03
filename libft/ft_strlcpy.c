/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:32:52 by shukondo          #+#    #+#             */
/*   Updated: 2025/10/27 22:49:34 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	j = 0;
	while (j < (size - 1) && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (len);
}
