/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:01:08 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/03 19:22:39 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	swap_stack(t_stack *s)
{
	int	first;
	int	second;
	int	tmp;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = (s->top + 1) % s->capacity;
	tmp = s->arr[first];
	s->arr[first] = s->arr[second];
	s->arr[second] = tmp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
