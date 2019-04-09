/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/04/09 11:11:37 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_oder(int a, int b)
{
	return (a <= b);
}

void	del_node(void *content, size_t size)
{
	if (content && size)
		;
}

int		main(int ac, char **av)
{
	t_list		*list;
	t_list		*node;
	int			num;
	int			i;

	if (ac > 1)
	{
		i = 0;
		list = NULL;
		while (++i < ac) 
		{
			num = ft_atoi(av[i]);
			if (!(node = ft_lstnew(&num, sizeof(int))))
				return (-1);
			ft_lstadd(&list, node);
		}
		ft_printf("sorted ? %d\n", ft_islist_sorted(list, ascending_oder)); 
		node = list;
		while (node)
		{
			ft_printf("%d\n", *(int *)node->content);
			node = node->next;
		}
		sort_list(&list);
		ft_printf("sorted ? %d\n", ft_islist_sorted(list, ascending_oder)); 
		node = list;
		while (node)
		{
			ft_printf("%d\n", *(int *)node->content);
			node = node->next;
		}
		ft_lstdel(&list, del_node);
	}
	return (0);
}
