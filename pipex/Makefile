# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:14:40 by gbazin            #+#    #+#              #
#    Updated: 2025/02/23 15:59:53 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := pipex

# COMPILATION #

CC := cc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
CFLAGS += -g3

# SOURCES #

SRCS_DIR := sources

SRCS += ${SRCS_DIR}/pipex_main.c
SRCS += ${SRCS_DIR}/pipex_utils_1.c
SRCS += ${SRCS_DIR}/pipex_utils_2.c
SRCS += ${SRCS_DIR}/pipex_utils_3.c
# HEADERS #

HEADERS_DIR := includes

HEADERS += ${HEADERS_DIR}/pipex.h

# LIBFT #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# OBJECTS #

OBJS := $(patsubst %.c, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_PATH)/includes -I${HEADERS_DIR}

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus