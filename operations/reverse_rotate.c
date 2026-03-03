/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:57:00 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/03 19:18:22 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	reverse_rotate_stack(t_stack *s)
{
	if (!s || s->size < 2)
		return ;
	s->top + (s->top - 1 + s->capacity) % s->capacity;
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
