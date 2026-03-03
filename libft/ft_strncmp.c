/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:32:46 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/26 16:11:52 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		if (*p1 == '\0')
			break ;
		p1++;
		p2++;
	}
	return (0);
}
