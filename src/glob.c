/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:33:14 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/08 21:04:50 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		update_glob(t_list *a, t_list *b, t_prgm *glob, int nb)
{
	MAX = STACK == 'A' ? get_list_max(a, nb) : get_list_max(b, nb);
	MIN = STACK == 'A' ? get_list_min(a, nb) : get_list_min(b, nb);
	VAL1 = STACK == 'A' ? *(int *)a->content : *(int *)(b)->content;
	VAL2 = STACK == 'A' ? *(int *)a->next->content : *(int *)b->next->content;
	if (nb == 3)
	{
		if (STACK == 'A')
			VAL3 = *(int *)a->next->next->content;
		else
			VAL3 = *(int *)b->next->next->content;
	}
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
	INIT_LEN = ft_lstcount(a);
}

