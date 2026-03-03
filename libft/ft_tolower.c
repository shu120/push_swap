/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:32:36 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/25 23:24:17 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	uc;

	if (c == EOF)
		return (EOF);
	uc = (unsigned char)c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 32);
	return (uc);
}
