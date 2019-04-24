/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/04/24 17:26:17 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_oder(int a, int b)
{
	return (a <= b);
}

int		error_exit(t_list *list)
{
	ft_putendl("Error");
	ft_lstdel(&list, del_node);
	return (-1);
}

int		main(int ac, char **av)
{
	t_list		*list;
	t_list		*node;

	if (ac > 1)
	{
		list = get_numbers_list(ac, av, 0, 0);
		ft_lstdel(&list, del_node);
	}
	return (0);
}
