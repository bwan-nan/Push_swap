/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islist_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:04:41 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/03/02 04:05:30 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_islist_sorted(t_list *list, int (*cmp)(int, int))
{
	if (!list || !list->next)
		return (1);
	if (cmp(*(int *)(list->content), *(int *)(list->next->content)) > 0)
		return (ft_islist_sorted(list->next, cmp));
	return (0);
}
