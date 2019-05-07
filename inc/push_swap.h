/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/07 20:55:09 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define LIST_LEN		glob->len
# define MEDIAN			glob->median
# define MAX			glob->max
# define MIN			glob->min
# define VAL1			glob->val1
# define VAL2			glob->val2
# define VAL3			glob->val3
# define STACK			glob->current_stack
# define ILEN			glob->initial_len

typedef struct			s_prgm
{
	int					len;
	int					median;
	int					max;
	int					min;
	int					val1;
	int					val2;
	int					val3;
	char					current_stack;
	int					initial_len;
}						t_prgm;


void					del_node(void *content, size_t size);

void					glob_init(t_list *a, t_prgm *glob);
void					update_glob(t_list *a, t_list *b, t_prgm *glob);


t_list					*create_list(int ac, char **av);	

void					sort_list(t_list **source);
void					custom_sort(t_list **a, t_list **b, t_prgm *glob);
int					ascending_order(void *a, void *b);
int					descending_order(void *a, void *b);
void					sort_3numbers(t_list **a, t_list **b, t_prgm *glob);

void					print_list(t_list *list);
void					print_stacks(t_list *a, t_list *b);

t_list					*get_sorted_copy(t_list *source);
int					get_median_value(t_list *source);
int					get_list_max(t_list *source);
int					get_list_min(t_list *source);

t_list					*error_exit(t_list *list);

void					push(t_list **a, t_list **b, char towards);
void					swap(t_list **a, t_list **b, char to_swap);
void					rotate(t_list **a, t_list **b, char to_rotate);
void					reverse_rotate(t_list **a, t_list **b, char to_rotate);

#endif
