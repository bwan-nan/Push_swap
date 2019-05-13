/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:00:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/13 17:04:27 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest, int verbose)
{
	ft_lstpush(&src->head, &dest->head);
	src->len--;
	dest->len++;
	if (verbose)
		ft_printf("p%c\n", ft_tolower(dest->stack_name));
}

void	swap(t_stack *current, int verbose)
{
	current->head = ft_lstswap(current->head, current->head->next);
	if (verbose)
		ft_printf("s%c\n", ft_tolower(STACK));
}

void	sswap(t_stack *a, t_stack *b, int verbose)
{
	swap(a, 0);
	swap(b, 0);
	if (verbose)
		ft_putendl("ss");
}

void	rotate(t_stack *current, int verbose)
{
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
