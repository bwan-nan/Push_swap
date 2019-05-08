# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cempassi <cempassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 23:18:40 by cempassi          #+#    #+#              #
#    Updated: 2019/05/08 20:14:05 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
LIB = $(LPATH)libft.a
LIBDB = $(LPATH)libftdb.a

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
SRCS += create_list.c
SRCS += sort_list2.c
SRCS += sort_top3.c
SRCS += instructions.c
SRCS += get_functions.c
SRCS += aux.c
SRCS += display.c

ARG = 2 3 4 5 6 7 8

DSYM = $(PUSH_SWAP).dSYM

OBJS = $(patsubst %.c, $(OPATH)%.o, $(SRCS))

vpath  %.c src/
vpath  %.h inc/
vpath  %.h libft/inc/

all : $(LIB) $(PUSH_SWAP)

run : all
	./$(PUSH_SWAP) $(ARG)

debug : $(LIBDB) $(SRCS)
	$(MAKE) -C $(LPATH) debug
	$(DEBUG) $(DFLAGS) $(CFLAGS) -o $(PUSH_SWAP) $^ 

$(PUSH_SWAP): $(LIB) $(OPATH) $(OBJS) $(INCS)
	$(CC) -o $@ $< $(OBJS)
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
	printf "$(RED)All objects from Push_swap folder removed.\n$(NC)"

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(PUSH_SWAP)
	printf "$(RED)$(PUSH_SWAP) deleted\n$(NC)"

re: fclean all

.PHONY: all clean fclean debug
.SILENT:
FORCE:
