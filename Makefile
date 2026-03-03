# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 15:17:51 by irdzhupy          #+#    #+#              #
#    Updated: 2026/03/03 16:32:42 by irdzhupy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTDIR = Libft
LIBFT = ${LIBFTDIR}/libft.a

SRCS = push_swap.c ft_atoi_strict.c Libft/ft_split.c

OBJS = ${SRCS:.c=.o}

CC = cc
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}
.c.o:
	${CC} ${FLAGS} -c $< -o $@
clean:
	rm -f ${OBJS}
	${MAKE} -C ${LIBFTDIR} clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${LIBFTDIR} fclean

re:	fclean all

.PHONY: all clean fclean re
