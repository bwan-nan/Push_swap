/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 01:19:38 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/05/18 13:40:21 by bwan-nan         ###   ########.fr       */
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
# define DISPLAY		glob->display
# define PUSHED			glob->pushed
# define ROTATED		glob->rotated

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
	int					initial_len;
	int					unsorted;
	int					pushed;
	int					rotated;
}						t_prgm;

typedef struct			s_stack
{
	char				stack_name;
	int					len;
	t_list				*head;
}						t_stack;

void					del_node(void *content, size_t size);
void					clear_stacks(t_stack *a, t_stack *b);

void					stacks_init(t_stack *a, t_stack *b, t_list *list);
void					glob_init(t_stack *a, t_prgm *glob);
void					update_glob(t_stack *current, t_prgm *glob, int nb);

int						create_stacks(t_stack *a, t_stack *b,
						int ac, char **av);

void					sort_list(t_list **source);
void					custom_sort(t_stack *a, t_stack *b,
						t_prgm *glob, int nb);
int						split_list(t_stack *current, t_stack *other,
						t_prgm *glob, int nb);
int						ascending_order(void *a, void *b);
int						descending_order(void *a, void *b);

void					sort_top3(t_stack *current, t_stack *other,
						t_prgm *glob, int nb);
void					sort_a(t_stack *a, t_stack *b, t_prgm *glob);
void					sort_b(t_stack *a, t_stack *b, t_prgm *glob);

void					print_list(t_list *list);
void					print_stacks(t_list *a, t_list *b);

t_list					*my_lstcpy(t_list *source, int (*cpy)(void *, void *));
t_list					*my_lstncpy(t_list *source, int size,
						int (*cpy)(void *, void *));
int						copy_values(void *dest, void *source);

t_list					*get_sorted_copy(t_list *source,
						t_prgm *glob, int size);
int						get_median_value(t_list *source);
int						get_list_max(t_list *source, int size);
int						get_list_min(t_list *source, int size);
t_list					*get_numbers_list(t_list *list, int ac,
						char **av, int num);
t_list					*ft_strsplit_tolist(t_list *list, char *str,
						int i, char *tmp);

t_list					*error_exit(t_list *list);

void					push(t_stack *src, t_stack *dest, int verbose);
void					swap(t_stack *current, int verbose);
void					sswap(t_stack *a, t_stack *b, int verbose);
void					rotate(t_stack *current, int verbose);
void					rrotate(t_stack *a, t_stack *b, int verbose);
void					reverse_rotate(t_stack *current, int verbose);
void					rreverse_rotate(t_stack *a, t_stack *b, int verbose);

int						exec(t_stack *a, t_stack *b, int display, char *line);
int						debug_mode(t_stack *a, t_stack *b, int ac, char **av);

#endif
