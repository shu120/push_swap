/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:07:17 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/06 00:05:39 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		curr = (a->top + i) % a->capacity;
		next = (a->top + i + 1) % a->capacity;
		if (a->arr[curr] > a->arr[next])
			return (0);
	}
	return (1);
}
