/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/14 15:34:57 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_prgm		glob;

	b.head = NULL;
	if (!(create_stacks(&a, &b, ac, av)))
		return (-1);
	glob_init(&a, &glob);
	custom_sort(&a, &b, &glob, glob.initial_len);
	clear_stacks(&a, &b);
	return (0);
}
