/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:26:05 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/17 18:26:59 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *current, int verbose)
{
	if (ft_lstcount(current->head) >= 2)
		ft_lstrotate(&current->head);
	if (verbose)
		ft_printf("r%c\n", ft_tolower(STACK));
}

void	rrotate(t_stack *a, t_stack *b, int verbose)
{
	rotate(a, 0);
	rotate(b, 0);
	if (verbose)
		ft_putendl("rr");
}

void	reverse_rotate(t_stack *current, int verbose)
{
	if (ft_lstcount(current->head) >= 2)
		ft_lstrevrotate(&current->head);
	if (verbose)
		ft_printf("rr%c\n", ft_tolower(STACK));
}

void	rreverse_rotate(t_stack *a, t_stack *b, int verbose)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	if (verbose)
		ft_putendl("rrr");
}
