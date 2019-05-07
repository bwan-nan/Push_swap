/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:50:15 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Duplicates not handled as errors yet

int		main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_prgm		glob;

	stack_b = NULL;
	if (!(stack_a = create_list(ac, av)))
		return (-1);
	print_stacks(stack_a, stack_b);
	glob_init(stack_a, &glob);
	custom_sort(&stack_a, &stack_b, &glob);

	ft_lstdel(&stack_a, del_node);
	ft_lstdel(&stack_b, del_node);
	return (0);
}
