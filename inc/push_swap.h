/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/04/24 17:05:59 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list					*ft_strsplit_tolist(t_list *list, char *str, int i, char *tmp);
void					del_node(void *content, size_t size);
void					sort_list(t_list **source);
void					print_list(t_list *list);

#endif
