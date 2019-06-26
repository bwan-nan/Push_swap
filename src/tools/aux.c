/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:39:01 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 13:45:29 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 <= elem2);
}

int		descending_order(void *a, void *b)
{
	int elem1;
	int elem2;

	elem1 = *(int *)a;
	elem2 = *(int *)b;
	return (elem1 >= elem2);
}

void	del_node(void *content, size_t size)
{
	if (content && size)
		free(content);
}

t_list	*error_exit(t_list *list)
{
	ft_putendl("Error");
	ft_lstdel(&list, del_node);
	return (NULL);
}

void	clear_stacks(t_stack *a, t_stack *b)
{
	ft_lstdel(&a->head, del_node);
	ft_lstdel(&b->head, del_node);
}
