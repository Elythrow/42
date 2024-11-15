# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 12:45:30 by gbazin            #+#    #+#              #
#    Updated: 2024/11/15 14:00:27 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL += get_next_line.c
GNL += get_next_line_utils.c

SRCS = ${GNL}

OBJS = ${SRCS:.c=.o}

NAME = gnl

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< ${<:.c=.o}

${NAME}:    ${OBJS}
		cc -o ${NAME} ${OBJS} ${CFLAGS} 

all:     ${NAME}

clean:
		rm -f ${OBJS}

fclean:    clean;
		rm -f ${NAME}

re:    fclean all

.PHONY: all clean fclean re bonus