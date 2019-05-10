/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/10 20:55:25 by bwan-nan         ###   ########.fr       */
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
	
//	print_stacks(a.head, b.head);
	custom_sort(&a, &b, &glob, glob.initial_len);


	//print_stacks(a.head, b.head);
	if (ft_islist_sorted(a.head, a.len, ascending_order))
		ft_putendl("Sorted");
	else
		ft_putendl("Not sorted");
	ft_printf("Nombre de passages dans sort_a : %d ; Total OP_A = %d\nNombre de passages dans sort_b : %d ; Total OP_B = %d\nNombre de passages dans split : %d ; Total OP_S = %d\n",
			glob.sort_a, glob.op_a, glob.sort_b, glob.op_b, glob.split, glob.op_s);
	ft_lstdel(&(a.head), del_node);
	ft_lstdel(&(a.head), del_node);
	return (0);
}
