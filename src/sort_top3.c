/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:13:42 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/10 19:46:19 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_b(t_stack *a, t_stack *b, t_prgm *glob)
{
//	ft_printf("VAL1 = %d, VAL2 = %d, VAL3 = %d, MIN = %d, MAX = %d\n",
//			VAL1, VAL2, VAL3, MIN, MAX);
	SB++;
	if (VAL1 == MAX)
	{
		push(b, a);
		swap(b, 1);
		push(b, a);
		push(b, a);
		OPB += 4;
	}
	else if (VAL1 == MIN)
	{
		swap(b, 1);
		push(b, a);
		swap(b, 1);
		push(b, a);
		if (VAL2 != MAX)
			swap(a, 1);
		push(b, a);
		OPB += VAL2 != MAX ? 6 : 5;
	}
	else
	{
		if (VAL2 == MIN)
		{
			push(b, a);
			swap(b, 1);
			push(b, a);
			swap(a, 1);
			push(b, a);
			OPB += 5;
		}
		else
		{
			swap(b, 1);
			push(b, a);
			push(b, a);
			push(b, a);
			OPB += 4;
		}
	}
}

static void		sort_a(t_stack *a, t_stack *b, t_prgm *glob)
{
	SA++;
	if (VAL1 == MAX)
	{
		swap(a, 1);
		push(a, b);
		swap(a, 1);
		push(b, a);
		if (VAL2 != MIN)
			swap(a, 1);
		OPA += VAL2 !=MIN ? 5 : 4;
	}
	else if (VAL1 == MIN)
	{
		push(a, b);
		swap(a, 1);
		push(b, a);
		OPA += 3;
	}
	else
	{
		if (VAL2 == MIN)
			swap(a, 1);
		else
		{
			push(a, b);
			swap(a, 1);
			push(b, a);
			swap(a, 1);
		}
		OPA += VAL2 == MIN ? 1 : 4;
	}
}

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

void			sort_top3(t_stack *current, t_stack *other, t_prgm *glob, int nb)
{
	update_glob(current, glob, nb);

	if (UNSORTED == 2)
	{
		swap(current, 1);
		if (STACK == 'B')
			while (nb--)
				push(current, other);
	}
	else if (nb == current->len && current->len <= 3)
	{
		if (STACK == 'A')
			simple_sort_a(current, glob);
		else
		{
			simple_sort_b(current, glob);
			while (nb--)
				push(current, other);
		}
	}
	else
	{
		STACK == 'A' ? sort_a(current, other, glob) : sort_b(other, current, glob);
		if (STACK == 'B')
			while (nb-- - 3)
				push(current, other);
	}
}	
