/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:55:39 by shukondo          #+#    #+#             */
/*   Updated: 2026/02/17 22:09:02 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static int	push_stack(t_stack *from, t_stack *to)
{
	int	i;

	if (!from || from->size == 0)
		return (0);
	i = to->size;
	while (i > 0)
	{
		to->arr[i] = to->arr[i - 1];
		i--;
	}
	to->arr[0] = from->arr[0];
	to->size++;
	i = 0;
	while (i < from->size - 1)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	from->size--;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_stack(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_stack(a, b))
		write(1, "pb\n", 3);
}
