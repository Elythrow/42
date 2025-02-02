# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 13:47:27 by gbazin            #+#    #+#              #
#    Updated: 2025/02/02 14:44:33 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := push_swap

# COMPILATION #

CC := cc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
CFLAGS += -g3

# SOURCES #

SRCS_DIR := sources

SRCS += ${SRCS_DIR}/push_swap.c
SRCS += ${SRCS_DIR}/push_swap_utils.c
SRCS += ${SRCS_DIR}/push_swap_sort.c
SRCS += ${SRCS_DIR}/push_swap_sort_utils.c
SRCS += ${SRCS_DIR}/push_swap_sort_big_utils.c
SRCS += ${SRCS_DIR}/push_swap_parsing.c
SRCS += ${SRCS_DIR}/push_swap_parsing_utils.c
SRCS += ${SRCS_DIR}/push_swap_operations_1.c
SRCS += ${SRCS_DIR}/push_swap_operations_2.c
SRCS += ${SRCS_DIR}/push_swap_operations_3.c
SRCS += ${SRCS_DIR}/push_swap_operations_utils.c

# HEADERS #

HEADERS_DIR := includes

HEADERS += ${HEADERS_DIR}/push_swap.h

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

.PHONY: all clean fclean re