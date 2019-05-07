/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:33:14 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:34:09 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		update_glob(t_list *a, t_list *b, t_prgm *glob)
{
	MAX = STACK == 'A' ? get_list_max(a) : get_list_max(b);
	MIN = STACK == 'A' ? get_list_min(a) : get_list_min(b);
	VAL1 = STACK == 'A' ? *(int *)a->content : *(int *)(b)->content;
	VAL2 = STACK == 'A' ? *(int *)a->next->content : *(int *)b->next->content;
	if ((STACK == 'A' && ft_lstcount(a) > 2) || (STACK == 'B' && ft_lstcount(b) > 2))
		VAL3 = STACK == 'A' ? *(int *)a->next->next->content
		: *(int *)b->next->next->content;
}

void		glob_init(t_list *a, t_prgm *glob)
{
	MEDIAN = 0;
	MAX = 0;
	MIN = 0;
	VAL1 = 0;
	VAL2 = 0;
	VAL3 = 0;
	STACK = 'A';
	ILEN = ft_lstcount(a);
}

