/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:55:39 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:39:29 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_stack *from, t_stack *to)
{
	int	val;

	if (!from || !to)
		return (0);
	if (from->size == 0)
		return (0);
	if (to->size >= to->capacity)
		return (0);
	val = from->arr[from->top];
	from->top = (from->top + 1) % from->capacity;
	from->size--;
	to->top = (to->top - 1 + to->capacity) % to->capacity;
	to->arr[to->top] = val;
	to->size++;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
