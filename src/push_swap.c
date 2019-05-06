/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/06 18:52:42 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*error_exit(t_list *list)
{
	ft_putendl("Error");
	ft_lstdel(&list, del_node);
	return (NULL);
}

void		glob_init(t_prgm *glob)
{
	MEDIAN = 0;
	MAX = 0;
	MIN = 0;
	VAL1 = 0;
	VAL2 = 0;
	VAL3 = 0;
	STACK = 'A';
}

//Duplicates not handled as errors yet

int		main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_prgm		glob;
	int			i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
	{
		if (!(stack_a = ft_strsplit_tolist(stack_a, av[1], 0, NULL)))
			return (-1);
	}
	else if (ac > 2)
	{
		if (!(stack_a = get_numbers_list(stack_a, ac, av, 0)))
			return (-1);
	}
	print_stacks(stack_a, stack_b);
	glob_init(&glob);
	custom_sort(&stack_a, &stack_b, &glob);
//	print_stacks(stack_a, stack_b);
	ft_lstdel(&stack_a, del_node);
	ft_lstdel(&stack_b, del_node);
	return (0);
}
