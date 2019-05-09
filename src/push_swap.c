/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/09 17:31:25 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Duplicates not handled as errors yet

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_prgm		glob;

	b.head = NULL;
	if (!(create_stacks(&a, &b, ac, av)))
		return (-1);
	glob_init(&a, &glob);
	
	print_stacks(a.head, b.head);
	custom_sort(&a, &b, &glob, glob.initial_len);

	print_stacks(a.head, b.head);
	ft_lstdel(&(a.head), del_node);
	ft_lstdel(&(a.head), del_node);
	return (0);
}
