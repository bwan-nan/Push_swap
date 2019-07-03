/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:02:26 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/07/03 23:31:10 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		parsing_error(t_stack *a, t_stack *b, char *line)
{
	clear_stacks(a, b);
	ft_strdel(&line);
	ft_putendl("Error");
	return (-1);
}

int				main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		*line;
	int			ret;
	int			display;

	b.head = NULL;
	display = 0;
	if (ac >= 3 && ft_strequ(av[1], "-v"))
	{
		display = isatty(0) ? 0 : 1;
		if (!debug_mode(&a, &b, ac, av))
			return (-1);
	}
	else if (!(create_stacks(&a, &b, ac, av)))
		return (-1);
	while (get_next_line(0, &line))
	{
		if ((ret = exec(&a, &b, display, line)) == -1)
			return (parsing_error(&a, &b, line));
		ft_strdel(&line);
	}
	ret = ft_islist_sorted(a.head, a.len, ascending_order) && !b.head;
	clear_stacks(&a, &b);
	ret == 0 ? ft_putendl("KO") : ft_putendl("OK");
	return (0);
}
