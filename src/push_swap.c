/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:16 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/05 20:47:04 by bwan-nan         ###   ########.fr       */
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

int		copy_values(void *dest, void *source)
{
	*(int *)dest = *(int *)source;
	return (0);
}

t_list		*get_sorted_copy(t_list *source)
{
	t_list	*new_list;

	if (!(new_list = ft_lstcpy(source, copy_values)))
		return (NULL);
	sort_list(&new_list);
	return (new_list);
}

int		get_median_value(t_list *source)
{
	int	k;
	int	index;

	index = ft_lstcount(source) / 2;
	k = -1;
	while (source && ++k < index)
		source = source->next;
	return (*(int *)source->content);
}

int		get_list_max(t_list *source)
{
	int	max;

	max = *(int *)source->content;
	while (source)
	{
		if (*(int *)source->content > max)
			max = *(int *)source->content;
		source = source->next;
	}
	return (max);
}

int		get_list_min(t_list *source)
{
	int	min;

	min = *(int *)source->content;
	while (source)
	{
		if (*(int *)source->content < min)
			min = *(int *)source->content;
		source = source->next;
	}
	return (min);
}

void		sort_three_numbers(t_list **a, t_list **b, char current_stack)
{
	int	max;
	int	min;
	int	num;

	if (ft_islist_sorted(*a, ascending_oder))
		return ;
	max = current_stack == 'A' ? get_list_max(*a) : get_list_max(*b);
	min = current_stack == 'A' ? get_list_min(*a) : get_list_min(*b);
	if ((num = current_stack == 'A' ? *(int *)(*a)->content
	: *(int *)(*b)->content) == max)
	{
		rotate(a, b, current_stack);
		if ((num = current_stack == 'A' ? *(int *)(*a)->content
		: *(int *)(*b)->content) != min)
			swap(a, b, current_stack);
	}
	else if ((num = current_stack == 'A' ? *(int *)(*a)->content
	: *(int *)(*b)->content) == min)
	{
		rotate(a, b, current_stack);
		if ((num = current_stack == 'A' ? *(int *)(*a)->content
	: *(int *)(*b)->content) == max)
			swap(a, b, current_stack);
		reverse_rotate(a, b, current_stack);
	}
	else
	{
		swap(a, b, current_stack);
		ft_putendl("OK");
		print_stacks(*a, *b);
		exit(1);
		sort_three_numbers(a, b, current_stack);
	}
 
}

void		custom_sort(t_list **a, t_list **b)
{
	t_list	*sorted_copy;
	int	median;
	int	len;

	if (!(sorted_copy = get_sorted_copy(*a)))
		return ;
	print_list(sorted_copy);
	median = get_median_value(sorted_copy);
	len = ft_lstcount(*a);
	ft_putendl("\n\n\n");

	while (ft_lstcount(*a) > len / 2)
	{
		if (*(int *)(*a)->content < median)
			push(a, b, 'B');
		else
			rotate(a, b, 'A');
	}
	print_stacks(*a, *b);
	sort_three_numbers(a, b, 'A');
	sort_three_numbers(a, b, 'B');
	print_stacks(*a, *b);
}

//Duplicates not handled as errors yet

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
	custom_sort(&stack_a, &stack_b);
//	print_stacks(stack_a, stack_b);
	ft_lstdel(&stack_a, del_node);
	return (0);
}
