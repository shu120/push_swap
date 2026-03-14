/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_compress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:13:40 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/14 18:16:42 by shukondo         ###   ########.fr       */
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

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
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
	return (-1);
}

void	idx_compress(t_stack *a)
{
	int	*copy;
	int	i;
	int	val;
	int	idx;

	copy = malloc(sizeof(int) * a->size);
	if (!copy)
		error_exit();
	copy_array(copy, a);
	insertion_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		val = a->arr[(a->top + i) % a->capacity];
		idx = find_index(copy, a->size, val);
		if (idx < 0)
			error_exit();
		a->arr[(a->top + i) % a->capacity] = idx;
		i++;
	}
	free(copy);
}
