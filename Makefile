# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irdzhupy <irdzhupy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/02 18:23:20 by irdzhupy          #+#    #+#              #
#    Updated: 2026/04/02 18:23:48 by irdzhupy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    := push_swap
HEADER  := push_swap.h

CC      := cc
CFLAGS  := -Wall -Wextra -Werror

INCLUDES	:= -I.

SRC_DIR		:= src
OP_DIR		:= operations
ALG_DIR		:= sorting

SRCS	= $(SRC_DIR)/main.c\
		  $(SRC_DIR)/parse_args.c\
		  $(SRC_DIR)/node_manipulations.c\
		  $(SRC_DIR)/stack_utils.c\
		  $(SRC_DIR)/utils.c\
		  $(SRC_DIR)/ft_split.c\
		  $(OP_DIR)/swap.c\
		  $(OP_DIR)/push.c\
		  $(OP_DIR)/rotate.c\
		  $(OP_DIR)/reverse_rotate.c\
		  $(ALG_DIR)/big_sort.c\
		  $(ALG_DIR)/small_sort.c\
		  $(ALG_DIR)/small_sort_utils.c

OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re