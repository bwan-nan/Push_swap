/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:13:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/04/24 17:28:25 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(void *content, size_t size)
{
	if (content && size)
		;
}

void	print_list(t_list *list)
{
	t_list *elem;

	elem = list;
	while (elem)
	{
		ft_printf("%d\n", *(int *)elem->content);
		elem = elem->next;
	}
}

t_list	*ft_strsplit_tolist(t_list *list, char *str, int i, char *tmp)
{
	t_list	*node;
	int		len;
	int		value;

	while (str[i])
	{
		len = 0;
		while (!(ft_iswhitespace(str[i + len])) && str[i + len])
			len++;
		if (len && (tmp = ft_strsub(str, i, len)))
		{
			if (!ft_isnumeric(tmp))
			{
				ft_strdel(&tmp);
				ft_lstdel(&list, del_node);
				return (NULL);
			}
			value = ft_atoi(tmp);
			if (!(node = ft_lstnew(&value, sizeof(int))))
				return (NULL);
			ft_lstadd(&list, node);
			ft_strdel(&tmp);
			i += len - 1;
		}
		i++;
	}
	return (list);
}

t_list	*get_numbers_list(int ac, char **av, int i, int num)
{
	t_list		*list;

	if (ac == 2)
	{
		if (!(list = ft_strsplit_tolist(list, av[1], 0, NULL)))
			return (error_exit(list));
	}
	else
	{
		while (++i < ac) 
		{
			if (!(ft_isnumeric(av[i])))
				return (error_exit(list));
			else
			{
				num = ft_atoi(av[i]);
				if (!(node = ft_lstnew(&num, sizeof(int))))
					return (-1);
				ft_lstadd(&list, node);
			}
		}
	}
	return (list);
}
