/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:56:33 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 13:45:33 by bwan-nan         ###   ########.fr       */
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

t_list			*ft_strsplit_tolist(t_list *list, char *str, int i, char *tmp)
{
	t_list		*node;
	int			len;
	int			value;

	while (str[i])
	{
		len = get_word_len(str + i);
		if (len && (tmp = ft_strsub(str, i, len)))
		{
			if (!ft_isinteger(tmp))
			{
				ft_strdel(&tmp);
				return (error_exit(list));
			}
			value = ft_atoi(tmp);
			if (!(node = ft_lstnew(&value, sizeof(int))))
				return (error_exit(list));
			ft_lstprepend(&list, node);
			ft_strdel(&tmp);
			i += len - 1;
		}
		i++;
	}
	return (list);
}

t_list			*get_numbers_list(t_list *list, int ac, char **av, int i)
{
	t_list	*node;
	int		num;

	while (++i < ac)
	{
		if (!(ft_isinteger(av[i])))
			return (error_exit(list));
		else
		{
			num = ft_atoi(av[i]);
			if (!(node = ft_lstnew(&num, sizeof(int))))
				return (error_exit(list));
			ft_lstprepend(&list, node);
		}
	}
	return (list);
}
