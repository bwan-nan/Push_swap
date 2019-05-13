/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:13:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/13 17:13:11 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			exec(t_stack *a, t_stack *b, char *line)
{
	if (ft_strequ(line, "sa"))
		swap(a, 0);
	else if (ft_strequ(line, "sb"))
		swap(b, 0);
	else if (ft_strequ(line, "ss"))
		sswap(a, b, 0);
	else if (ft_strequ(line, "ra"))
		rotate(a, 0);
	else if (ft_strequ(line, "rb"))
		rotate(b, 0);
	else if (ft_strequ(line, "rr"))
		rrotate(a, b, 0);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(a, 0);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(b, 0);
	else if (ft_strequ(line, "rrr"))
		rreverse_rotate(a, b, 0);
	else if (ft_strequ(line, "pa"))
		push(b, a, 0);
	else if (ft_strequ(line, "pb"))
		push(a, b, 0);
	else
		return (-1);
	return (ft_islist_sorted(a->head, a->len, ascending_order) && !b->head);
}
