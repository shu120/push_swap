/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:01:08 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:39:50 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_stack *s)
{
	int	first;
	int	second;
	int	tmp;

	if (!s || s->size < 2)
		return (0);
	first = s->top;
	second = (s->top + 1) % s->capacity;
	tmp = s->arr[first];
	s->arr[first] = s->arr[second];
	s->arr[second] = tmp;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap(a);
	swapped_b = swap(b);
	if (swapped_a || swapped_b)
		write(1, "ss\n", 3);
}
