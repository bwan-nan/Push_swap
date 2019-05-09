/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:33:14 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/09 15:30:23 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		update_glob(t_stack *current, t_prgm *glob, int nb)
{
	MAX = get_list_max(current->head, nb);
	MIN = get_list_min(current->head, nb);
	VAL1 = *(int *)current->head->content;
	VAL2 = *(int *)current->head->next->content;
	if (nb == 3)
		VAL3 = *(int *)current->head->next->next->content;
}

void		glob_init(t_stack *a, t_prgm *glob)
{
	MEDIAN = 0;
	MAX = 0;
	MIN = 0;
	VAL1 = 0;
	VAL2 = 0;
	VAL3 = 0;
	INIT_LEN = a->len;
}

