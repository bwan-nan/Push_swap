/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/06 16:07:19 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ascending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 <= elem2);
}

static int	descending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 >= elem2);
}

void		sort_list(t_list **source)
{
	ft_lst_mergesort(source, ascending_order); 
	ft_lstrev(source);
}

void		update_glob(t_list *a, t_list *b, t_prgm *glob)
{
	MAX = STACK == 'A' ? get_list_max(a) : get_list_max(b);
	MIN = STACK == 'A' ? get_list_min(a) : get_list_min(b);
	VAL1 = STACK == 'A' ? *(int *)a->content : *(int *)(b)->content;
	VAL2 = STACK == 'A' ? *(int *)a->next->content : *(int *)b->next->content;
	VAL3 = STACK == 'A' ? *(int *)a->next->next->content
	: *(int *)b->next->next->content;
}

void		sort_3numbers_a(t_list **a, t_list **b, t_prgm *glob)
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

void		sort_3numbers_b(t_list **a, t_list **b, t_prgm *glob)
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

void		sort_three_numbers(t_list **a, t_list **b, t_prgm *glob)
{
	if ((STACK == 'A' && ft_islist_sorted(*a, 3, ascending_order))
	|| (STACK == 'B' && ft_islist_sorted(*b, 3, descending_order)))
		return ;
	update_glob(*a, *b, glob);
	STACK == 'A' ? sort_3numbers_a(a, b, glob) : sort_3numbers_b(a, b, glob);;
}

void		custom_sort(t_list **a, t_list **b, t_prgm *glob)
{
	t_list	*sorted_copy;

	if (!(sorted_copy = get_sorted_copy(*a)))
		return ;
	//print_list(sorted_copy);
	MEDIAN = get_median_value(sorted_copy);
	LIST_LEN = ft_lstcount(*a);
	ft_putendl("\n\n\n");

	while (ft_lstcount(*a) > (LIST_LEN % 2 ? LIST_LEN / 2 + 1 : LIST_LEN / 2))
	{
		if (*(int *)(*a)->content < MEDIAN)
			push(a, b, 'B');
		else
			rotate(a, b, 'A');
	}
	
	print_stacks(*a, *b);
/*	STACK = 'A';
	sort_three_numbers(a, b, glob);
	STACK = 'B';
	sort_three_numbers(a, b, glob);
			*/
	print_stacks(*a, *b);
}
