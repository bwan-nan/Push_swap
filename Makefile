# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 20:37:34 by bwan-nan          #+#    #+#              #
#    Updated: 2019/06/06 20:37:36 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
LIB = $(LPATH)libft.a

# Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

CC = Clang
COMPILE = $(CC) -c
DEBUG = $(CC) -g

MKDIR = mkdir -p
CLEANUP = rm -rf

WFLAGS += -Wall
WFLAGS += -Werror
WFLAGS += -Wextra
DFLAGS = -fsanitize=address
IFLAGS = -I $(IPATH) -I $(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

OPATH = obj/
SPATH = src/
IPATH = inc/
LPATH = libft/
LIPATH = libft/inc/

INCS += push_swap.h 
INCS += libft.h 
INCS += ft_printf.h 
INCS += output.h 
INCS += strings.h 
INCS += binary.h 
INCS += conversions.h 
INCS += lists.h 

SRCS += push_swap.c
SRCS += glob.c
SRCS += create_stacks.c
SRCS += create_list.c
SRCS += sort_list.c
SRCS += split_list.c
SRCS += copy_list.c
SRCS += sort_top3.c
SRCS += sort_a.c
SRCS += sort_b.c
SRCS += instructions1.c
SRCS += instructions2.c
SRCS += get_functions.c
SRCS += aux.c
SRCS += display.c
SRCS += checker.c
SRCS += exec.c

SRCS_CH += checker.c
SRCS_CH += create_stacks.c
SRCS_CH += create_list.c
SRCS_CH += copy_list.c
SRCS_CH += get_functions.c
SRCS_CH += glob.c
SRCS_CH += exec.c
SRCS_CH += instructions1.c
SRCS_CH += instructions2.c
SRCS_CH += aux.c
SRCS_CH += display.c

SRCS_PS += push_swap.c
SRCS_PS += glob.c
SRCS_PS += create_stacks.c
SRCS_PS += create_list.c
SRCS_PS += sort_list.c
SRCS_PS += split_list.c
SRCS_PS += copy_list.c
SRCS_PS += sort_top3.c
SRCS_PS += sort_a.c
SRCS_PS += sort_b.c
SRCS_PS += instructions1.c
SRCS_PS += instructions2.c
SRCS_PS += get_functions.c
SRCS_PS += aux.c
SRCS_PS += display.c

ARG = 8 9 5 3 2 -1 6

DSYMP = $(PUSH_SWAP).dSYM
DSYMC = $(CHECKER).dSYM
DSYM = $(DSYMC) + $(DSYMP)

OBJS = $(patsubst %.c, $(OPATH)%.o, $(SRCS))
OBJS_CH = $(patsubst %.c, $(OPATH)%.o, $(SRCS_CH))
OBJS_PS = $(patsubst %.c, $(OPATH)%.o, $(SRCS_PS))

vpath  %.c src/
vpath  %.h inc/
vpath  %.h libft/inc/

all : $(LIB) $(PUSH_SWAP) $(CHECKER)

run : all
	./$(PUSH_SWAP) $(ARG)

$(PUSH_SWAP): $(LIB) $(OPATH) $(OBJS_PS) $(INCS)
	$(CC) -o $@ $< $(OBJS_PS)
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(CHECKER): $(LIB) $(OPATH) $(OBJS_CH) $(INCS)
	$(CC) -o $@ $< $(OBJS_CH)
	printf "$(GREEN)$@ is ready.\n$(NC)"

$(OBJS) : $(OPATH)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@
	printf "$(CYAN)Compiling $<\n$(NC)"

$(LIB) : FORCE
	$(MAKE) -C $(LPATH)

$(LIBDB) :
	$(MAKE) -C $(LPATH) debug

$(OPATH):
	$(MKDIR) $@

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OBJS)
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(DSYM)
	printf "$(RED)All objects removed from Libft\n$(NC)"
	printf "$(RED)All objects removed from Push_swap\n$(NC)"

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(PUSH_SWAP)
	$(CLEANUP) $(CHECKER)
	printf "$(RED)$(PUSH_SWAP) deleted\n$(NC)"
	printf "$(RED)$(CHECKER) deleted\n$(NC)"

re: fclean all

.PHONY: all clean fclean debug
.SILENT:
FORCE:
