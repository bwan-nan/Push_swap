/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:57:48 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_list(t_list **a, t_list **b, t_prgm *glob)
{
	while (ft_lstcount(*a) > (LIST_LEN % 2 ? LIST_LEN / 2 + 1 : LIST_LEN / 2))
	{
		if (*(int *)(*a)->content < MEDIAN)
			push(a, b, 'B');
		else
			rotate(a, b, 'A');
	}
}

void		custom_sort(t_list **a, t_list **b, t_prgm *glob)
{
	t_list	*sorted_copy;

	if (ft_islist_sorted(*a, ILEN, ascending_order))
		return ;
	if (!(sorted_copy = get_sorted_copy(*a)))
		return ;
	MEDIAN = get_median_value(sorted_copy);
	LIST_LEN = ft_lstcount(*a);

	ft_putendl("\n\n\n");
	print_stacks(*a, *b);

	split_list(a, b, glob);
	
	if (ft_lstcount(*a) > 3)
		custom_sort(a, b, glob);
	else
	{
		STACK = 'A';
		sort_3numbers(a, b, glob);
		STACK = 'B';
		sort_3numbers(a, b, glob);
	}
	print_stacks(*a, *b);

		
	ft_lstdel(&sorted_copy, del_node);
}
