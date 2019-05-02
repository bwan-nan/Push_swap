/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/02 19:27:02 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_oder(int a, int b)
{
	return (a <= b);
}

t_list		*error_exit(t_list *list)
{
	ft_putendl("Error");
	ft_lstdel(&list, del_node);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

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
	push(&stack_a, &stack_b, 'B');
	ft_putendl("\n\n");
	print_stacks(stack_a, stack_b);

	push(&stack_a, &stack_b, 'B');
	ft_putendl("\n\n");
	print_stacks(stack_a, stack_b);

	swap(&stack_a, &stack_b, 'S');
	ft_putendl("\n\n");
	print_stacks(stack_a, stack_b);
	
	rotate(&stack_a, &stack_b, 'A');
	ft_putendl("\n\n");
	print_stacks(stack_a, stack_b);

	reverse_rotate(&stack_a, &stack_b, 'A');
	ft_putendl("\n\n");
	print_stacks(stack_a, stack_b);
	ft_lstdel(&stack_a, del_node);
	return (0);
}
