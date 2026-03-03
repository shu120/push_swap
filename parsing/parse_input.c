/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:54:54 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/03 20:58:09 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

static int	count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**sp;

	count = 0;
	i = 1;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp)
			return (-1);
		j = 0;
		while (sp[j])
		{
			count++;
			j++;
		}
		free_split(sp);
		i++;
	}
	return (count);
}

static int	fill_numbers(int argc, char **argv, int *arr)
{
	int		i;
	int		j;
	int		k;
	long	val;
	char	**sp;

	k = 0;
	i = 1;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp)
			return (0);
		j = 0;
		while (sp[j])
		{
			if (!is_valid_number(sp[j]))
				return (free_split(sp), 0);
			val = ft_atol(sp[j]);
			if (val < INT_MIN || val > INT_MAX)
				return (free_split(sp), 0);
			arr[k++] = (int)val;
			j++;
		}
		free_split(sp);
		i++;
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int	count;
	int	*tmp;

	if (argc < 2)
		return (0);
	count = count_tokens(argc, argv);
	if (count <= 0)
		error_exit();
	tmp = malloc(sizeof(int) * count);
	if (!tmp)
		error_exit();
	if (!fill_numbers(argc, argv, tmp))
	{
		free(tmp);
		error_exit();
	}
	if (check_duplicate(tmp, count))
	{
		free(tmp);
		error_exit();
	}
	a->arr = tmp;
	a->size = count;
	a->capacity = count;
	a->top = 0;
	return (1);
}
