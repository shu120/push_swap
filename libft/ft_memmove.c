/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:33:03 by shukondo          #+#    #+#             */
/*   Updated: 2025/10/25 18:34:12 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (dptr == sptr)
		return (dest);
	if (dptr < sptr)
	{
		while (n--)
			*dptr++ = *sptr++;
	}
	else
	{
		dptr += n;
		sptr += n;
		while (n--)
			*--dptr = *--sptr;
	}
	return (dest);
}
