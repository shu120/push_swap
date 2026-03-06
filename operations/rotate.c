/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:56:15 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:39:46 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_stack *s)
{
	if (!s || s->size < 2)
		return (0);
	s->top = (s->top + 1) % s->capacity;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = rotate(a);
	moved_b = rotate(b);
	if (moved_a || moved_b)
		write(1, "rr\n", 3);
}
