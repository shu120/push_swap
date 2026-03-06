/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:05:27 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/06 21:34:30 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	small_sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[a->top];
	y = a->arr[(a->top + 1) % a->capacity];
	z = a->arr[(a->top + 2) % a->capacity];
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	find_min(t_stack *a)
{
	int	i;
	int	min;
	int	pos;
	int	val;

	i = 0;
	min = a->arr[a->top];
	pos = 0;
	while (i < a->size)
	{
		val = a->arr[(a->top + i) % a->capacity];
		if (val < min)
		{
			min = val;
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	small_sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = find_min(a);
		if (pos <= a->size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			pos = a->size - pos;
			while (pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	small_sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		small_sort_3(a);
	else if (a->size <= 5)
		small_sort_5(a, b);
}
