# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:50:23 by gbazin            #+#    #+#              #
#    Updated: 2025/04/08 10:51:21 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
FLAGS=-Wall -Werror -Wextra -pthread
SRCS=main.c utils.c routines.c

all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all