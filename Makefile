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

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Source files
SRCS    := main.c node.c parse_args.c ft_split.c operations.c
OBJS    := $(SRCS:.c=.o)

# Header
HEADER  := push_swap.h

# Target executable
NAME    := push_swap

# Default rule
all: $(NAME)

# Link objects into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule for compiling .c -> .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all
