/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:59:30 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:24:48 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	copy_values(void *dest, void *source)
{
	*(int *)dest = *(int *)source;
	return (0);
}

t_list		*get_sorted_copy(t_list *source)
{
	t_list	*new_list;

	if (!(new_list = ft_lstcpy(source, copy_values)))
		return (NULL);
	ft_lst_mergesort(&new_list, ascending_order);
	ft_lstrev(&new_list);
	return (new_list);
}

int		get_median_value(t_list *source)
{
	int	k;
	int	index;

	index = ft_lstcount(source) / 2;
	k = -1;
	while (source && ++k < index)
		source = source->next;
	return (*(int *)source->content);
}

int		get_list_max(t_list *source)
{
	int	max;

	max = *(int *)source->content;
	while (source)
	{
		if (*(int *)source->content > max)
			max = *(int *)source->content;
		source = source->next;
	}
	return (max);
}

int		get_list_min(t_list *source)
{
	int	min;

	min = *(int *)source->content;
	while (source)
	{
		if (*(int *)source->content < min)
			min = *(int *)source->content;
		source = source->next;
	}
	return (min);
}
