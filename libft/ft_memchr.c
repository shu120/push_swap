/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:33:12 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/21 23:10:28 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
