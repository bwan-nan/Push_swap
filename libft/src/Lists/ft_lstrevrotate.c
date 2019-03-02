/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 03:43:39 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/03/02 03:58:25 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrevrotate(t_list **alst)
{
	t_list	*first;
	t_list	*current;
	t_list	*before_last;

	first = *alst;
	current = first;
	while (current->next)
	{
		before_last = current;
		current = current->next;
	}
	current->next = first;
	*alst = current;
	before_last->next = NULL;
}
