/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/02 19:23:42 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list					*ft_strsplit_tolist(t_list *list, char *str, int i, char *tmp);
void					del_node(void *content, size_t size);
void					sort_list(t_list **source);
void					print_list(t_list *list);
void					print_stacks(t_list *a, t_list *b);
t_list					*get_numbers_list(t_list *list, int ac, char **av, int num);
t_list					*error_exit(t_list *list);
void					push(t_list **a, t_list **b, char towards);
void					swap(t_list **a, t_list **b, char to_swap);
void					rotate(t_list **a, t_list **b, char to_rotate);
void					reverse_rotate(t_list **a, t_list **b, char to_rotate);

#endif
