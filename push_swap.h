/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:32:09 by shukondo          #+#    #+#             */
/*   Updated: 2026/03/07 00:33:22 by shukondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
	int	top;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		parse_input(int argc, char **argv, t_stack *a);
int		is_valid_number(const char *s);
long	ft_atol(const char *s);
int		check_duplicate(int *arr, int size);
void	error_exit(void);

int		is_sorted(t_stack *a);
void	small_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	idx_compress(t_stack *a);		

#endif