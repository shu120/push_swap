/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:59:18 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 01:36:59 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	parse_input(argc, argv, &a);
	b.arr = malloc(sizeof(int) * a.capacity);
	if (!b.arr)
		return (free(a.arr), 1);
	b.size = 0;
	b.capacity = a.capacity;
	b.top = 0;
	if (is_sorted(&a))
		return (free(a.arr), free(b.arr), 0);
	if (a.size <= 5)
		small_sort(&a, &b);
	else
	{
		idx_compress(&a);
		radix_sort(&a, &b);
	}
	free(a.arr);
	free(b.arr);
	return (0);
}
