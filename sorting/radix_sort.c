/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:32:44 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:32:48 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		while (size--)
		{
			if (((a->arr[a->top] >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
