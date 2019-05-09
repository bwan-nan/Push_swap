/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:13:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/09 15:15:46 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_word_len(char *str)
{
	int	i;

	i = 0;
	while (!(ft_iswhitespace(str[i])) && str[i])
		i++;
	return (i);
}

static t_list	*ft_strsplit_tolist(t_list *list, char *str, int i, char *tmp)
{
	t_list		*node;
	int		len;
	int		value;

	while (str[i])
	{
		len = get_word_len(str + i);
		if (len && (tmp = ft_strsub(str, i, len)))
		{
			if (!ft_isnumeric(tmp))
			{
				ft_strdel(&tmp);
				return (error_exit(list));
			}
			value = ft_atoi(tmp);
			if (!(node = ft_lstnew(&value, sizeof(int))))
				return (error_exit(list));
			ft_lstadd(&list, node);
			ft_strdel(&tmp);
			i += len - 1;
		}
		i++;
	}
	return (list);
}

static t_list	*get_numbers_list(t_list *list, int ac, char **av, int num)
{
	t_list		*node;
	int		i;

	i = 0;
	while (++i < ac) 
	{
		if (!(ft_isnumeric(av[i])))
			return (error_exit(list));
		else
		{
			num = ft_atoi(av[i]);
			if (!(node = ft_lstnew(&num, sizeof(int))))
				return (error_exit(list));
			ft_lstadd(&list, node);
		}
	}
	return (list);
}

int			create_stacks(t_stack *a, t_stack *b, int ac, char **av)
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
	ft_lstrev(&list);
	a->head = list;
	a->len = ft_lstcount(list);
	a->stack_name = 'A';
	b->head = NULL;
	b->len = 0;
	b->stack_name = 'B';
	return (1);
}
