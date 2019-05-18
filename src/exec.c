/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:13:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 17:28:31 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_with_display(t_stack *a, t_stack *b, char *line)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb"))
		ft_strequ(line, "sa") ? swap(a, 1) : swap(b, 1);
	else if (ft_strequ(line, "ss"))
		sswap(a, b, 1);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb"))
		ft_strequ(line, "ra") ? rotate(a, 1) : rotate(b, 1);
	else if (ft_strequ(line, "rr"))
		rrotate(a, b, 1);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrb"))
		ft_strequ(line, "rra") ? reverse_rotate(a, 1) : reverse_rotate(b, 1);
	else if (ft_strequ(line, "rrr"))
		rreverse_rotate(a, b, 1);
	else if (ft_strequ(line, "pa") || ft_strequ(line, "pb"))
		ft_strequ(line, "pa") ? push(b, a, 1) : push(a, b, 1);
	else
		return (-1);
	print_stacks(a->head, b->head);
	return (0);
}

int			exec(t_stack *a, t_stack *b, int display, char *line)
{
	if (display)
		return (exec_with_display(a, b, line));
	else if (ft_strequ(line, "sa") || ft_strequ(line, "sb"))
		ft_strequ(line, "sa") ? swap(a, 0) : swap(b, 0);
	else if (ft_strequ(line, "ss"))
		sswap(a, b, 0);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb"))
		ft_strequ(line, "ra") ? rotate(a, 0) : rotate(b, 0);
	else if (ft_strequ(line, "rr"))
		rrotate(a, b, 0);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrb"))
		ft_strequ(line, "rra") ? reverse_rotate(a, 0) : reverse_rotate(b, 0);
	else if (ft_strequ(line, "rrr"))
		rreverse_rotate(a, b, 0);
	else if (ft_strequ(line, "pa") || ft_strequ(line, "pb"))
		ft_strequ(line, "pa") ? push(b, a, 0) : push(a, b, 0);
	else
		return (-1);
	return (0);
}
