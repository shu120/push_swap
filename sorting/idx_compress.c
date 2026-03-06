/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_compress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:13:40 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:37:19 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	copy_array(int *dst, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		dst[i] = a->arr[(a->top + i) % a->capacity];
		i++;
	}
}

static int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	idx_compress(t_stack *a)
{
	int	*copy;
	int	i;
	int	val;

	copy = malloc(sizeof(int) * a->size);
	if (!copy)
		error_exit();
	copy_array(copy, a);
	qsort(copy, a->size, sizeof(int), cmp_int);
	i = 0;
	while (i < a->size)
	{
		val = a->arr[(a->top + i) % a->capacity];
		a->arr[(a->top + i) % a->capacity] = find_index(copy, a->size, val);
		i++;
	}
	free(copy);
}
