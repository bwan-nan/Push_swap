/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:13:42 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/08 23:20:28 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top3_a(t_list **a, t_list **b, t_prgm *glob)
{
	if (VAL1 == MAX)
	{
		if (VAL2 == MIN)
			rotate(a, b, STACK);
		else
		{
			swap(a, b, STACK);
			reverse_rotate(a, b, STACK);
		}
	}
	else if (VAL1 != MIN && VAL1 != MAX)
		VAL2 == MIN ? swap(a, b, STACK) : reverse_rotate(a, b, STACK);
	else
	{
		reverse_rotate(a, b, STACK);
		swap(a, b, STACK);
	}
}

static void	sort_top3_b(t_list **a, t_list **b, t_prgm *glob)
{
	if (VAL1 == MAX && VAL2 == MIN)
	{
			reverse_rotate(a, b, STACK);
			swap(a, b, STACK);
	}
	else if (VAL1 != MIN && VAL1 != MAX)
	{
		if (VAL2 == MIN)
		{
			rotate(a, b, 'B');
			rotate(a, b, 'B');
			push(a, b, 'A');
			reverse_rotate(a, b, 'B');
			reverse_rotate(a, b, 'B');
			push(a, b, 'A');
			push(a, b, 'A');
		}
		else
		{
			rotate(a, b, 'B');
			rotate(a, b, 'B');
			push(a, b, 'A');
			reverse_rotate(a, b, 'B');
			push(a, b, 'A');
			reverse_rotate(a, b, 'B');
			push(a, b, 'A');
		}
	}
	else
	{
		if (VAL2 == MAX)
			rotate(a, b, STACK);
		else
		{
			swap(a, b, STACK);
			reverse_rotate(a, b, STACK);
		}
	}
}

void		sort_top3(t_list **a, t_list **b, t_prgm *glob, int nb)
{
//	if ((STACK == 'A' && ft_islist_sorted(*a, nb, ascending_order))
//	|| (STACK == 'B' && ft_islist_sorted(*b, nb, descending_order)))
//		return ;
	update_glob(*a, *b, glob, nb);
	ft_printf("NB = %d ; STACK = %c ;\nVAL1 = %d ; VAL2 = %d, VAL3 = %d\n", nb, STACK,
			VAL1, VAL2, VAL3);
	print_stacks(*a, *b);
	if (nb == 2)
	{
		if (STACK == 'A' && VAL1 > VAL2)
		   swap(a, b, STACK);	
		else if (STACK == 'B')
		{
			if (VAL1 < VAL2)
				swap(a, b, STACK);
			push(a, b, 'A');
			push(a, b, 'A');
		}
	}
	else
		STACK == 'A' ? sort_top3_a(a, b, glob) : sort_top3_b(a, b, glob);
}

