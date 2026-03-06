/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:57:00 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 02:03:18 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverse_rotate(t_stack *s)
{
	int	last;
	int	val;

	if (!s || s->size < 2)
		return (0);
	last = (s->top + s->size - 1) % s->capacity;
	val = s->arr[last];
	s->top = (s->top - 1 + s->capacity) % s->capacity;
	s->arr[s->top] = val;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = reverse_rotate(a);
	moved_b = reverse_rotate(b);
	if (moved_a || moved_b)
		write(1, "rrr\n", 4);
}
