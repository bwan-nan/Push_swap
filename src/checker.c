/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:02:26 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/13 19:44:21 by bwan-nan         ###   ########.fr       */
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
	while (get_next_line(0, &line) && (ret = exec(&a, &b, line)) != 1)
	{
		if (ret == -1)
		{
			ft_putendl("Error");
			ft_lstdel(&(a.head), del_node);
			ft_lstdel(&(b.head), del_node);
			return (-1);
		}
		ft_strdel(&line);
	}
	//print_stacks(a.head, b.head);
	ft_lstdel(&(a.head), del_node);
	ft_lstdel(&(b.head), del_node);
	ret == 0 ? ft_putendl("KO") : ft_putendl("OK");
	return (ret == 0 ? 0 : 1);
}
