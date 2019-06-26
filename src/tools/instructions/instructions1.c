/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:27:48 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 17:33:16 by bwan-nan         ###   ########.fr       */
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
	if (ft_lstcount(current->head) >= 2)
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
