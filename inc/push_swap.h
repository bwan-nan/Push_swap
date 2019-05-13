/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/13 18:41:41 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define MEDIAN			glob->median
# define MAX			glob->max
# define MIN			glob->min
# define VAL1			glob->val1
# define VAL2			glob->val2
# define VAL3			glob->val3
# define PUSHED			glob->pushed
# define INIT_LEN		glob->initial_len
# define UNSORTED		glob->unsorted
# define OPA			glob->op_a
# define SA				glob->sort_a
# define OPB			glob->op_b
# define SB				glob->sort_b
# define SPLIT			glob->split
# define OPS			glob->op_s
# define TEN			glob->ten
# define OPT			glob->op_t

# define STACK			current->stack_name

# define VALUE			current->head->content

typedef struct			s_prgm
{
	int					median;
	int					max;
	int					min;
	int					val1;
	int					val2;
	int					val3;
	int					pushed;
	int					initial_len;
	int					unsorted;
	int					op_a;
	int					op_b;
	int					op_s;
	int					sort_a;
	int					sort_b;
	int					split;
	int					ten;
	int					op_t;
}						t_prgm;

typedef struct			s_stack
{
	char				stack_name;
	int					len;
	t_list				*head;
}						t_stack;

void					del_node(void *content, size_t size);

void					stacks_init(t_stack *a, t_stack *b, t_list *list);
void					glob_init(t_stack *a, t_prgm *glob);
void					update_glob(t_stack *current, t_prgm *glob, int nb);


int						create_stacks(t_stack *a, t_stack *b, int ac, char **av);	

void					sort_list(t_list **source);
void					custom_sort(t_stack *a, t_stack *b, t_prgm *glob, int nb);
int						ascending_order(void *a, void *b);
int						descending_order(void *a, void *b);
void					sort_top3(t_stack *current, t_stack *other, t_prgm *glob, int nb);

void					print_list(t_list *list);
void					print_stacks(t_list *a, t_list *b);

int						copy_values(void *dest, void *source);
t_list					*get_sorted_copy(t_list *source, t_prgm *glob, int size);
int						get_median_value(t_list *source);
int						get_list_max(t_list *source, int size);
int						get_list_min(t_list *source, int size);

t_list					*error_exit(t_list *list);

void					push(t_stack *src, t_stack *dest, int verbose);
void					swap(t_stack *current, int verbose);
void					sswap(t_stack *a, t_stack *b, int verbose);
void					rotate(t_stack *current, int verbose);
void					rrotate(t_stack *a, t_stack *b, int verbose);
void					reverse_rotate(t_stack *current, int verbose);
void					rreverse_rotate(t_stack *a, t_stack *b, int verbose);

int						exec(t_stack *a, t_stack *b, char *line);

#endif
