/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/08 23:14:42 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list **a, t_list **b, t_prgm *glob, int nb)
{
	if (STACK == 'A' && ft_islist_sorted(*a, nb, ascending_order))
	{
		return (1);
	}
	else if (STACK == 'B' && ft_islist_sorted(*b, nb, descending_order))
	{
		while (nb--)
			push(a, b, 'A');
		return (1);
	}
	return (0);
}

static int	unsorted_top(t_list *source, t_prgm *glob)
{
	t_list	*rev;
	t_list	*sorted_copy;
	int		total;
	int		i;

	total = ft_lstcount(source);
	sorted_copy = get_sorted_copy(source, glob, ft_lstcount(source));
	ft_lstrev(&sorted_copy);
	rev = ft_lstcpy(source, copy_values);
	i = 0;
/*	print_list(rev);
	ft_putendl("\n\n");
	print_list(sorted_copy);*/
	while (rev && sorted_copy)
	{
		if (*(int *)rev->content != *(int *)sorted_copy->content)
			break ;
		i++;
		sorted_copy = sorted_copy->next;
		rev = rev->next;
	}
	ft_lstdel(&rev, del_node);
	ft_printf("unsorted = %d\n", total - i);
	return (total - i);
}

static int	split_list (t_list **a, t_list **b, t_prgm *glob, int nb)
{
	t_list	*sorted_copy;
	int		pushed;
	int		limit;

	pushed = 0;
	limit = nb % 2 ? nb / 2 + 1 : nb / 2;
	if (STACK == 'A')
		sorted_copy = get_sorted_copy(*a, glob, nb);
	else
		sorted_copy = get_sorted_copy(*b, glob, nb);
	print_list(sorted_copy);
	while (nb > limit)
	{
		if ((STACK == 'A' && *(int *)(*a)->content < MEDIAN)
		|| (STACK == 'B' && *(int *)(*b)->content > MEDIAN))
		{
			push(a, b, STACK == 'A' ? 'B' : 'A');
			pushed++;
			nb--;
		}
		else
			rotate(a, b, STACK);
	}
	ft_lstdel(&sorted_copy, del_node);
	return (pushed);
}

void		custom_sort(t_list **a, t_list **b, t_prgm *glob, int nb)
{
	int		ret;
	int		pushed;

	if (is_sorted(a, b, glob, nb))
		return ;
	if ((ret = unsorted_top(*a, glob)) <= 3)
	{
		if (STACK == 'B' && ret == 0 && nb <= 3)
			sort_top3(a, b, glob, nb);
		else if (STACK == 'B' && nb > 3 && ret == 0)
		{
			pushed = split_list(a, b, glob, nb);
			if (STACK == 'A')
			{
				ft_printf("rest = %d\n", nb - pushed);
				custom_sort(a, b, glob, nb - pushed);
				STACK = 'B';
				custom_sort(a, b, glob, pushed);
			}
			else
			{
				custom_sort(a, b, glob, pushed);
				STACK = 'A';
				ft_printf("nb - pushed = %d\n", nb -pushed);
				custom_sort(a, b, glob, nb - pushed);
			}
		}
		else
			sort_top3(a, b, glob, ret); 
	}
	else
	{
		print_stacks(*a, *b);
		pushed = split_list(a, b, glob, nb);
		if (STACK == 'A')
		{
			ft_printf("rest = %d\n", nb - pushed);
			custom_sort(a, b, glob, nb - pushed);
			STACK = 'B';
			custom_sort(a, b, glob, pushed);
		}
		else
		{
			custom_sort(a, b, glob, pushed);
			STACK = 'A';
			ft_printf("nb - pushed = %d\n", nb -pushed);
			custom_sort(a, b, glob, nb - pushed);
		}
	}
	print_stacks(*a, *b);
}
