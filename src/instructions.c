/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:00:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/09 15:06:18 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	ft_lstpush(&src->head, &dest->head);
	src->len--;
	dest->len++;
}

void	swap(t_stack *current, int verbose)
{
	current->head = ft_lstswap(current->head, current->head->next);
	if (verbose)
		;
}

void	sswap(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
}

void	rotate(t_stack *current, int verbose)
{
	ft_lstrotate(&current->head);
	if (verbose)
		;
}

void	rrotate(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
}

void	reverse_rotate(t_stack *current, int verbose)
{
	ft_lstrevrotate(&current->head);
	if (verbose)
			;
}

void	rreverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
}
