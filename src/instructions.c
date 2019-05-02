/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:00:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/02 19:26:44 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b, char towards)
{
	if (towards == 'A')
		ft_lstpush(b, a);
	else if (towards == 'B')
		ft_lstpush(a, b);
}

void	swap(t_list **a, t_list **b, char to_swap)
{
	if (to_swap == 'A')
		*a = ft_lstswap(*a, (*a)->next);
	else if (to_swap == 'B')
		*b = ft_lstswap(*b, (*b)->next);
	else if (to_swap == 'S')
	{
		*a = ft_lstswap(*a, (*a)->next);
		*b = ft_lstswap(*b, (*b)->next);
	}
}

void	rotate(t_list **a, t_list **b, char to_rotate)
{
	if (to_rotate == 'A')
		ft_lstrotate(a);
	else if (to_rotate == 'B')
		ft_lstrotate(b);
	else if (to_rotate == 'R')
	{
		ft_lstrotate(a);
		ft_lstrotate(b);
	}
}

void	reverse_rotate(t_list **a, t_list **b, char to_rotate)
{
	if (to_rotate == 'A')
		ft_lstrevrotate(a);
	else if (to_rotate == 'B')
		ft_lstrevrotate(b);
	else if (to_rotate == 'R')
	{
		ft_lstrevrotate(a);
		ft_lstrevrotate(b);
	}
}
