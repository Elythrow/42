# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:14:40 by gbazin            #+#    #+#              #
#    Updated: 2025/03/01 17:04:00 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := cub3D

# COMPILATION #

CC := cc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
CFLAGS += -g3

# SOURCES #

SRCS_DIR := sources

SRCS += ${SRCS_DIR}/fractol_main.c
SRCS += ${SRCS_DIR}/fractol_parsing.c
SRCS += ${SRCS_DIR}/fractol_calcul.c
SRCS += ${SRCS_DIR}/fractol_render.c
SRCS += ${SRCS_DIR}/fractol_init.c
SRCS += ${SRCS_DIR}/fractol_events.c

# HEADERS #

HEADERS_DIR := includes

HEADERS += ${HEADERS_DIR}/cub3d.h

# LIBFT #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# MINILIBX #

MLX_PATH = ./minilibx
MLX = $(MLX_PATH)/libmlx.a
LIBS = -Lminilibx-linux -L/usr/lib -lXext -lX11 -lm -lft

# OBJECTS #

OBJS := $(patsubst %.c, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) ${LIBS}

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH)/includes -I${HEADERS_DIR} -I${MLX_PATH} -c $< -o $@ 

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
