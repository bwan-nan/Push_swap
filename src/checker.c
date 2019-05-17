/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:02:26 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/17 15:27:40 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		*line;
	int			ret;

	b.head = NULL;
	if (!(create_stacks(&a, &b, ac, av)))
		return (-1);
	while (get_next_line(0, &line))
	{
		if ((ret = exec(&a, &b, line)) == -1)
		{
			ft_putendl("Error");
			clear_stacks(&a, &b);
			return (-1);
		}
		ft_strdel(&line);
	}
	ret = ft_islist_sorted(a.head, a.len, ascending_order) && !b.head;
	clear_stacks(&a, &b);
	ret == 0 ? ft_putendl("KO") : ft_putendl("OK");
	return (0);
}
