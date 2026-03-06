/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:07:17 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:31:11 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size < 2)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[(a->top + i) % a->capacity]
			> a->arr[(a->top + i + 1) % a->capacity])
			return (0);
		i++;
	}
	return (1);
}
