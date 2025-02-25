# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:12:15 by gbazin            #+#    #+#              #
#    Updated: 2025/02/25 14:13:48 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -Llibft -lft
INCLUDES = -I./include -I./libft -I./minilibx-linux
SRCS = 	srcs/main.c srcs/julia_set.c srcs/zoom.c srcs/utils.c srcs/render.c \
		srcs/events.c srcs/mandelbrot_set.c
OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft