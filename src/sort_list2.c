/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/10 21:00:28 by bwan-nan         ###   ########.fr       */
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
		return (1);
	}
	return (0);
}

t_list		*list_index(t_list	*list, int len, int nb)
{
	int		index;

	index = len - nb;
	while (list && index--)
		list = list->next;
	return (list);
}

static int	unsorted_top(t_stack *current, t_prgm *glob, int nb)
{
	t_list	*rev;
	t_list	*sorted_copy;
	t_list	*head1;
	t_list	*head2;
	int		i;

	head1 = get_sorted_copy(current->head, glob, current->len);
	if (STACK == 'A')
		ft_lstrev(&head1);
	sorted_copy = list_index(head1, current->len, nb);
	head2 = ft_lstcpy(current->head, copy_values);
	rev = list_index(head2, current->len, nb);
	i = 0;
	while (rev && sorted_copy && i < nb)
	{
		if (*(int *)rev->content != *(int *)sorted_copy->content)
			break ;
		i++;
		sorted_copy = sorted_copy->next;
		rev = rev->next;
	}
	ft_lstdel(&head1, del_node);
	ft_lstdel(&head2, del_node);
//	ft_printf("unsorted = %d\n", total - i);
	return (nb - i);
}

static int	split_list (t_stack *current, t_stack *other, t_prgm *glob, int nb)
{
	t_list	*sorted_copy;
	int		pushed;
	int		rotated;
	int		limit;
	int		test;
	int		tmp;

	SPLIT++;
	tmp = current->len;
	pushed = 0;
	rotated = 0;
	limit = nb % 2 ? nb / 2 + 1 : nb / 2;
	sorted_copy = get_sorted_copy(current->head, glob, nb);
	if (STACK == 'B')
		ft_lstrev(&sorted_copy);
	while (nb > limit)
	{
		test = (nb + pushed) % 2 ? *(int *)VALUE < MEDIAN : *(int *)VALUE <= MEDIAN;
		if ((STACK == 'A' && *(int *)VALUE < MEDIAN)
		|| (STACK == 'B' && ((nb + pushed) % 2 ? *(int *)VALUE > MEDIAN : *(int *)VALUE >= MEDIAN)))
		{
			push(current, other);
			OPS++;
			pushed++;
			nb--;
			//ft_printf("nb = %d, limit = %d, pushed = %d, MEDIAN = %d\n", nb, limit, pushed, MEDIAN);
	/*	if (STACK == 'A')
			print_stacks(current->head, other->head);
		else
			print_stacks(other->head, current->head);*/
		}
		else
		{
			rotate(current, 1);
			OPS++;
			rotated++;
		}
	}
	if ((pushed + nb != INIT_LEN && STACK == 'A')
	|| (pushed + nb != tmp && STACK == 'B'))
	{
		while (rotated--)
		{
			reverse_rotate(current, 1);
			OPS++;
		}
	}
	ft_lstdel(&sorted_copy, del_node);
	return (pushed);
}

void		custom_sort(t_stack *current, t_stack *other, t_prgm *glob, int nb)
{
	int		pushed;

	if (is_sorted(current, other, nb))
	{
	/*	ft_printf("sorted  = 1 :  STACK = %c, nb = %d\n", STACK, nb);
		if (STACK == 'A')
			print_stacks(current->head, other->head);
		else
			print_stacks(other->head, current->head);*/
	}
	else if ((UNSORTED = unsorted_top(current, glob, nb)) <= 3)
	{
	//	ft_printf("unsorted = %d,   STACK = %c, nb = %d\n", UNSORTED, STACK, nb);

		sort_top3(current, other, glob, nb); 
	/*	if (STACK == 'A')
			print_stacks(current->head, other->head);
		else
			print_stacks(other->head, current->head);*/
	}
	else
	{
	//	ft_printf("SPLIT :   STACK = %c, nb = %d\n", STACK, nb);
		pushed = split_list(current, other, glob, nb);
	/*	if (STACK == 'A')
			print_stacks(current->head, other->head);
		else
			print_stacks(other->head, current->head);*/
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
