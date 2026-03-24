# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::  #
#    Makefile                                           :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: idzhup <idzhup@student.42.fr>              +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/03/11 14:00:00 by idzhup            #+#    #+#            #
#    Updated: 2026/03/11 14:00:00 by idzhup           ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

# Target executable
NAME    := push_swap

# Header
HEADER  := push_swap.h

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Source files
INCLUDES	:= -I.

SRC_DIR		:= src
OP_DIR		:= operations
ALG_DIR		:= sorting

SRCS	= $(SRC_DIR)/main.c\
		  $(SRC_DIR)/parse_args.c\
		  $(SRC_DIR)/error.c\
		  $(SRC_DIR)/node_manipulations.c\
		  $(SRC_DIR)/stack_utils.c\
		  $(SRC_DIR)/utils.c\
		  $(SRC_DIR)/ft_split.c\
		  $(OP_DIR)/swap.c\
		  $(OP_DIR)/push.c\
		  $(OP_DIR)/rotate.c\
		  $(OP_DIR)/reverse_rotate.c\
		  $(ALG_DIR)/small_sort.c

OBJS    := $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Link objects into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

# Pattern rule for compiling .c -> .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

# Phony targets
.PHONY: all clean fclean re
