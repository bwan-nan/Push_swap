/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:11:06 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/17 19:41:55 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*init_split(t_stack *current, int *len, t_prgm *glob, int nb)
{
	t_list	*new_list;

	*len = current->len;
	new_list = get_sorted_copy(current->head, glob, nb);
	if (STACK == 'B')
		ft_lstrev(&new_list);
	PUSHED = 0;
	ROTATED = 0;
	return (new_list);
}

static int		is_pair(int number)
{
	if (number % 2 == 0)
		return (1);
	return (0);
}

static int		is_to_push(t_stack *current, t_prgm *glob, int nb)
{
	if (STACK == 'A' && *(int *)VALUE < MEDIAN)
		return (1);
	else if (STACK == 'B')
	{
		if (!is_pair(nb + PUSHED) && *(int *)VALUE > MEDIAN)
			return (1);
		else if (is_pair(nb + PUSHED) && *(int *)VALUE >= MEDIAN)
			return (1);
	}
	return (0);
}

int				split_list(t_stack *current,
				t_stack *other, t_prgm *glob, int nb)
{
	t_list	*sorted_copy;
	int		limit;
	int		stack_len;

	sorted_copy = init_split(current, &stack_len, glob, nb);
	limit = nb % 2 ? nb / 2 + 1 : nb / 2;
	while (nb > limit)
	{
		if (is_to_push(current, glob, nb))
		{
			push(current, other, 1);
			PUSHED++;
			nb--;
		}
		else if (++ROTATED)
			rotate(current, 1);
	}
	if (PUSHED + nb != stack_len)
		while (ROTATED--)
			reverse_rotate(current, 1);
	ft_lstdel(&sorted_copy, del_node);
	return (PUSHED);
}
