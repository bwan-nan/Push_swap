/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:10:22 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 14:02:24 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	ft_printf("{yellow}STACK A | STACK B\n------------------\n{nc}");
	while (a && b)
	{
		ft_printf("%4d{yellow}%5c{nc}%4d\n",
		*(int *)a->content, '|', *(int *)b->content);
		a = a->next;
		b = b->next;
	}
	if (a)
	{
		while (a)
		{
			ft_printf("%4d{yellow}%5c{nc}\n", *(int *)a->content, '|');
			a = a->next;
		}
	}
	else if (b)
	{
		while (b)
		{
			ft_printf("{yellow}%9c{nc}%4d\n", '|', *(int *)b->content);
			b = b->next;
		}
	}
}

void	print_list(t_list *list)
{
	t_list *elem;

	elem = list;
	while (elem)
	{
		ft_printf("%d\n", *(int *)elem->content);
		elem = elem->next;
	}
}
