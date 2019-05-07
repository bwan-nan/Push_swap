/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:25:40 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:29:03 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3numbers_a(t_list **a, t_list **b, t_prgm *glob)
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

static void	sort_3numbers_b(t_list **a, t_list **b, t_prgm *glob)
{
	if (VAL1 == MAX && VAL2 == MIN)
	{
			reverse_rotate(a, b, STACK);
			swap(a, b, STACK);
	}
	else if (VAL1 != MIN && VAL1 != MAX)
		VAL2 == MIN ? reverse_rotate(a, b, STACK) : swap(a, b, STACK);
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

void		sort_3numbers(t_list **a, t_list **b, t_prgm *glob)
{
	int		simple;

	simple = 0;
	if ((STACK == 'A' && ft_lstcount(*a) == 2) || (STACK == 'B' && ft_lstcount(*b) == 2))
		simple = 1;
	if ((STACK == 'A' && ft_islist_sorted(*a, 3, ascending_order))
	|| (STACK == 'B' && ft_islist_sorted(*b, 3, descending_order)))
		return ;
	update_glob(*a, *b, glob);
	if (simple)
	{
		if (STACK == 'A' && VAL1 > VAL2)
		   swap(a, b, STACK);	
		else if (STACK == 'B' && VAL1 < VAL2)
			swap(a, b, STACK);
	}
	else
		STACK == 'A' ? sort_3numbers_a(a, b, glob) : sort_3numbers_b(a, b, glob);
}

