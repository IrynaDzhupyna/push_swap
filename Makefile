# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/20 15:48:18 by irdzhupy          #+#    #+#              #
#    Updated: 2026/02/20 16:39:09 by irdzhupy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

LIBFTDIR = Libft
LIBFT = ${LIBFTDIR}/libft.a

SRCS = push_swap.c utils_1.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${LIBFT} ${OBJS}
	cp ${LIBFT} ${NAME}
	ar -rcs ${NAME} ${OBJS}
.c.o:
	${CC} ${CFLAGS} -c $< -o $@
clean:
	rm -f ${OBJS}
	${MAKE} -C ${LIBFTDIR} clean

fclean: clean
        rm -f ${NAME}
        ${MAKE} -C ${LIBFTDIR} fclean

re:     fclean all

.PHONY: all clean fclean re
