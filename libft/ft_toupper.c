/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:32:34 by shukondo          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:52 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	if (c == EOF)
		return (EOF);
	uc = (unsigned char)c;
	if (uc >= 'a' && uc <= 'z')
		return (uc - 32);
	return (uc);
}
