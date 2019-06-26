/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:53:02 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 14:26:06 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_duplicates(t_list *list)
{
	t_list	*cpy;
	t_list	*elem;

	if (!(cpy = my_lstcpy(list, copy_values)))
		return (0);
	ft_lst_mergesort(&cpy, ascending_order);
	elem = cpy;
	while (elem->next)
	{
		if (*(int *)elem->content == *(int *)elem->next->content)
		{
			ft_lstdel(&cpy, del_node);
			return (1);
		}
		elem = elem->next;
	}
	ft_lstdel(&cpy, del_node);
	return (0);
}

static int		exit_error(t_list **list)
{
	ft_lstdel(list, del_node);
	ft_putendl("Error");
	return (0);
}

int				debug_mode(t_stack *a, t_stack *b, int ac, char **av)
{
	t_list	*list;

	list = NULL;
	if (ac == 3)
	{
		if (!(list = ft_strsplit_tolist(list, av[2], 0, NULL)))
			return (0);
	}
	else
	{
		if (!(list = get_numbers_list(list, ac, av, 1)))
			return (0);
	}
	if (check_duplicates(list))
		return (exit_error(&list));
	stacks_init(a, b, list);
	ft_printf("{green}INITIALIZATION\n------------------{nc}\n");
	print_stacks(a->head, b->head);
	return (1);
}

int				create_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	t_list	*list;

	list = NULL;
	if (ac == 2)
	{
		if (!(list = ft_strsplit_tolist(list, av[1], 0, NULL)))
			return (0);
	}
	else if (ac > 2)
	{
		if (!(list = get_numbers_list(list, ac, av, 0)))
			return (0);
	}
	else
		return (0);
	if (check_duplicates(list))
		return (exit_error(&list));
	stacks_init(a, b, list);
	return (1);
}
