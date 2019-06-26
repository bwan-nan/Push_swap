/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:49:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/17 18:59:43 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		case_1(t_stack *a, t_stack *b, t_prgm *glob)
{
	swap(a, 1);
	push(a, b, 1);
	swap(a, 1);
	push(b, a, 1);
	if (VAL2 != MIN)
		swap(a, 1);
}

static void		case_2(t_stack *a, t_stack *b)
{
	push(a, b, 1);
	swap(a, 1);
	push(b, a, 1);
}

static void		case_3(t_stack *a, t_stack *b, t_prgm *glob)
{
	if (VAL2 == MIN)
		swap(a, 1);
	else
	{
		push(a, b, 1);
		swap(a, 1);
		push(b, a, 1);
		swap(a, 1);
	}
}

void			sort_a(t_stack *a, t_stack *b, t_prgm *glob)
{
	if (VAL1 == MAX)
		case_1(a, b, glob);
	else if (VAL1 == MIN)
		case_2(a, b);
	else
		case_3(a, b, glob);
}
