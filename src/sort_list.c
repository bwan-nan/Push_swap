/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:05:52 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/04/09 15:27:29 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ascending_order(void *a, void *b)
{
	int *elem1;
	int *elem2;

	elem1 = (int *)a;
	elem2 = (int *)b;
	return (*elem1 <= *elem2);
}

void		sort_list(t_list **source)
{
	ft_lst_mergesort(source, ascending_order); 
	ft_lstrev(source);
}
