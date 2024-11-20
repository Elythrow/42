# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 17:09:51 by gbazin            #+#    #+#              #
#    Updated: 2024/11/20 11:16:47 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c
SRC_UTILS = $(addprefix utils/, ft_putnbr.c ft_putunbr.c ft_put_ptr.c ft_put_hex.c)
SRC_PRINTERS = $(addprefix printers/, ft_print_c.c ft_print_s.c ft_print_d.c ft_print_u.c ft_print_p.c ft_print_x.c)

OBJS := $(SRC:%.c=%.o)
OBJS_UTILS := $(SRC_UTILS:%.c=%.o)
OBJS_PRINTERS := $(SRC_PRINTERS:%.c=%.o)

NAME = libftprintf.a
CC = cc
CCFLAGS = -Werror -Wall -Wextra

%.o: %.c
	$(CC) -I. $(CCFLAGS) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_UTILS) $(OBJS_PRINTERS)
	ar rcs $(NAME) $(OBJS) $(OBJS_UTILS) $(OBJS_PRINTERS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_UTILS) $(OBJS_PRINTERS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear: fclean 
	clear

test: all
	gcc $(CCFLAGS) -I. -L. -lftprintf test.c