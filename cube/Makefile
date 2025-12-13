# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 12:00:00 by gbazin            #+#    #+#              #
#    Updated: 2025/12/05 16:58:25 by gbazin           ###   ########.fr        #
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

SRCS += ${SRCS_DIR}/main.c
SRCS += ${SRCS_DIR}/cleaning.c
SRCS += ${SRCS_DIR}/exec_game.c
SRCS += ${SRCS_DIR}/visual.c
SRCS += ${SRCS_DIR}/commands.c
SRCS += ${SRCS_DIR}/init.c
SRCS += ${SRCS_DIR}/movement.c
SRCS += ${SRCS_DIR}/raycasting.c
SRCS += ${SRCS_DIR}/raycasting_utils.c
SRCS += ${SRCS_DIR}/rotation.c
SRCS += ${SRCS_DIR}/texture.c
SRCS += ${SRCS_DIR}/parser/parser_color.c
SRCS += ${SRCS_DIR}/parser/parser_error.c
SRCS += ${SRCS_DIR}/parser/parser_file.c
SRCS += ${SRCS_DIR}/parser/parser_file2.c
SRCS += ${SRCS_DIR}/parser/parser_free.c
SRCS += ${SRCS_DIR}/parser/parser_map.c
SRCS += ${SRCS_DIR}/parser/parser_texture.c
SRCS += ${SRCS_DIR}/parser/parser_utils.c
SRCS += ${SRCS_DIR}/parser/parser_validate.c
SRCS += ${SRCS_DIR}/parser/parser_validate_check.c

# HEADERS #

HEADERS_DIR := includes

HEADERS += ${HEADERS_DIR}/cub3d.h
HEADERS += ${HEADERS_DIR}/parser.h

# LIBFT #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# MINILIBX #

MLX_PATH = ./minilibx-linux
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