/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/09 18:04:43 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *current, t_stack *other, int nb)
{
	if (STACK == 'A' && ft_islist_sorted(current->head, nb, ascending_order))
		return (1);
	if (STACK == 'B' && ft_islist_sorted(current->head, nb, descending_order))
	{
		while (nb--)
			push(current, other);
		//print_stacks(other->head, current->head);
		return (1);
	}
	return (0);
}

static int	unsorted_top(t_stack *current, t_prgm *glob, int nb)
{
	t_list	*rev;
	t_list	*sorted_copy;
	int		i;

	sorted_copy = get_sorted_copy(current->head, glob, current->len);
	if (STACK == 'A')
		ft_lstrev(&sorted_copy);
	rev = ft_lstcpy(current->head, copy_values);
	i = 0;
/*	print_list(rev);
	ft_putendl("\n\n");
	print_list(sorted_copy);*/
	while (rev && sorted_copy && i < nb)
	{
		if (*(int *)rev->content != *(int *)sorted_copy->content)
			break ;
		i++;
		sorted_copy = sorted_copy->next;
		rev = rev->next;
	}
	ft_lstdel(&rev, del_node);
	ft_lstdel(&sorted_copy, del_node);
//	ft_printf("unsorted = %d\n", total - i);
	return (nb - i);
}

static int	split_list (t_stack *current, t_stack *other, t_prgm *glob, int nb)
{
	t_list	*sorted_copy;
	int		pushed;
	int		rotated;
	int		limit;

	pushed = 0;
	rotated = 0;
	limit = nb % 2 ? nb / 2 + 1 : nb / 2;
	sorted_copy = get_sorted_copy(current->head, glob, nb);
	if (STACK == 'B')
		ft_lstrev(&sorted_copy);
	print_list(sorted_copy);
	if (STACK == 'B')
		print_stacks(other->head, current->head);
	ft_printf("limit = %d ; nb = %d\n", limit, nb);
	while (nb > limit)
	{
		if ((STACK == 'A' && *(int *)current->head->content < MEDIAN)
		|| (STACK == 'B' && *(int *)current->head->content > MEDIAN))
		{
			push(current, other);
			pushed++;
			ft_printf("limit = %d ; nb = %d ; pushed = %d\n", limit, nb, pushed);
			print_stacks(other->head, current->head);
			nb--;
		}
		else
		{
			rotate(current, 1);
			rotated++;
		}
	}
	while (rotated--)
		reverse_rotate(current, 1);
	ft_lstdel(&sorted_copy, del_node);
	if (STACK == 'A')
		print_stacks(current->head, other->head);
	else
		print_stacks(other->head, current->head);
	return (pushed);
}

void		custom_sort(t_stack *current, t_stack *other, t_prgm *glob, int nb)
{
	int		ret;
	int		pushed;

	if (is_sorted(current, other, nb))
	{
		ft_printf("%c is sorted\n", STACK);
		return ;
	}
	if ((ret = unsorted_top(current, glob, nb)) <= 3)
	{
			ft_printf("unsorted top = %d from %c ; nb = %d\n", ret, STACK, nb);
			sort_top3(current, other, glob, nb); 
	}
	else
	{
		pushed = split_list(current, other, glob, nb);
		ft_printf("pushed = %d from %c\n", pushed, STACK);
		if (STACK == 'A')
		{
			custom_sort(current, other, glob, nb - pushed);
			custom_sort(other, current, glob, pushed);
		}
		else
		{
			custom_sort(other, current, glob, pushed);
			custom_sort(current, other, glob, nb - pushed);
		}
	}
}
