/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:13:42 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/17 19:06:16 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simple_sort_a(t_stack *a, t_prgm *glob)
{
	if (VAL1 == MAX)
	{
		if (VAL2 == MIN)
			rotate(a, 1);
		else
		{
			swap(a, 1);
			reverse_rotate(a, 1);
		}
	}
	else if (VAL1 != MIN && VAL1 != MAX)
		VAL2 == MIN ? swap(a, 1) : reverse_rotate(a, 1);
	else
	{
		reverse_rotate(a, 1);
		swap(a, 1);
	}
}

static void		simple_sort_b(t_stack *b, t_prgm *glob)
{
	if (VAL1 == MAX)
	{
		reverse_rotate(b, 1);
		swap(b, 1);
	}
	else if (VAL1 == MIN)
	{
		if (VAL2 == MAX)
			rotate(b, 1);
		else
		{
			rotate(b, 1);
			swap(b, 1);
		}
	}
	else
	{
		if (VAL2 == MAX)
			swap(b, 1);
		else
			reverse_rotate(b, 1);
	}
}

static void		sort_top2(t_stack *current, t_stack *other, int nb)
{
	swap(current, 1);
	if (STACK == 'B')
		while (nb--)
			push(current, other, 1);
}

void			sort_top3(t_stack *current,
				t_stack *other, t_prgm *glob, int nb)
{
	update_glob(current, glob, nb);
	if (UNSORTED == 2)
		sort_top2(current, other, nb);
	else if (nb == current->len && current->len <= 3)
	{
		if (STACK == 'A')
			simple_sort_a(current, glob);
		else
		{
			simple_sort_b(current, glob);
			while (nb--)
				push(current, other, 1);
		}
	}
	else
	{
		if (STACK == 'A')
			sort_a(current, other, glob);
		else
		{
			sort_b(other, current, glob);
			while (nb-- - 3)
				push(current, other, 1);
		}
	}
}
