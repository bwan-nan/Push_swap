/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/08 20:05:18 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_half(t_list **a, t_list **b, t_prgm *glob, int pushed)
{
	ft_printf("%d\n", ft_lstcount(*a));
	if (STACK == 'A' && ft_lstcount(*a) > 3)
		custom_sort(a, b, glob);
	else if (STACK == 'B' && *b)
		custom_sort(a, b, glob);
	else
	{
		STACK = 'A';
		sort_3numbers(a, b, glob);
		STACK = 'B';
		SIMPLE = pushed % 2 ? 0 : 1;
		sort_3numbers(a, b, glob);
		print_stacks(*a, *b);
		while (pushed--)
			push(a, b, 'A');
		print_stacks(*a, *b);
	}
}

static int	split_list(t_list **a, t_list **b, t_prgm *glob)
{
	int		len;
	int		k;
	int		pushed;

	k = LIST_LEN % 2 ? LIST_LEN / 2 + 1 : LIST_LEN / 2;
	//ft_printf("%d\n", MEDIAN);
	pushed = 0;
	while ((len = ft_lstcount(*a)) > k)
	{
		if (STACK == 'A' && *(int *)(*a)->content < MEDIAN)
		{
			push(a, b, 'B');
			pushed++;
		}
		else if (STACK == 'B' && *(int *)(*a)->content > MEDIAN)
		{
			push(a, b, 'A');
			pushed++;
		}
		else
			rotate(a, b, STACK);
	}
	return (pushed);
}

void		custom_sort(t_list **a, t_list **b, t_prgm *glob)
{
	t_list	*sorted_copy;
	int		pushed;

	pushed = 0;
	if (ft_islist_sorted(*a, ILEN, ascending_order))
		return ;
	LIST_LEN = ft_lstcount(*a);
	sorted_copy = STACK == 'A' ? get_sorted_copy(*a, LIST_LEN) : get_sorted_copy(*b, PUSHED);
	if (STACK == 'B')
	{
		ft_printf("PUSHED = %d\n", PUSHED);
		print_list(sorted_copy);
	}
	MEDIAN = get_median_value(sorted_copy);

	print_stacks(*a, *b);

	if (ILEN > 3)
		pushed = split_list(a, b, glob);
	PUSHED = pushed;
	ft_printf("pushed= %d\n", pushed);
	sort_half(a, b, glob, pushed);
//	STACK = 'B';
//	sort_half(a, b, glob, pushed);


	//print_stacks(*a, *b);
		
	ft_lstdel(&sorted_copy, del_node);
}
