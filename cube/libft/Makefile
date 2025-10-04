# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:35:40 by gbazin            #+#    #+#              #
#    Updated: 2025/02/26 14:22:21 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := libft.a

# COMPILATION #

CC := cc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra

AR := ar

ARFLAGS := rsc

# SOURCES #

SRCS_DIR := sources
PRINTF_DIR := ft_printf

SRCS += ${SRCS_DIR}/ft_atod.c
SRCS += ${SRCS_DIR}/ft_atoi.c
SRCS +=	${SRCS_DIR}/ft_atol.c
SRCS +=	${SRCS_DIR}/ft_atoll.c
SRCS +=	${SRCS_DIR}/ft_free_tab.c
SRCS += ${SRCS_DIR}/ft_get_next_line.c
SRCS +=	${SRCS_DIR}/ft_bzero.c
SRCS +=	${SRCS_DIR}/ft_calloc.c
SRCS +=	${SRCS_DIR}/ft_countchr.c
SRCS +=	${SRCS_DIR}/ft_isalnum.c
SRCS +=	${SRCS_DIR}/ft_isalpha.c
SRCS +=	${SRCS_DIR}/ft_isascii.c
SRCS +=	${SRCS_DIR}/ft_isdigit.c
SRCS +=	${SRCS_DIR}/ft_isprint.c
SRCS +=	${SRCS_DIR}/ft_memchr.c
SRCS +=	${SRCS_DIR}/ft_memcmp.c
SRCS +=	${SRCS_DIR}/ft_memcpy.c
SRCS +=	${SRCS_DIR}/ft_memmove.c
SRCS +=	${SRCS_DIR}/ft_memset.c
SRCS +=	${SRCS_DIR}/ft_strchr.c
SRCS +=	${SRCS_DIR}/ft_strdup.c
SRCS +=	${SRCS_DIR}/ft_strlcat.c
SRCS +=	${SRCS_DIR}/ft_strlcpy.c
SRCS +=	${SRCS_DIR}/ft_strlen.c
SRCS +=	${SRCS_DIR}/ft_strncmp.c
SRCS +=	${SRCS_DIR}/ft_strnstr.c
SRCS +=	${SRCS_DIR}/ft_strrchr.c
SRCS +=	${SRCS_DIR}/ft_tolower.c
SRCS +=	${SRCS_DIR}/ft_toupper.c
SRCS += ${SRCS_DIR}/ft_itoa.c 
SRCS +=	${SRCS_DIR}/ft_putchar_fd.c 
SRCS +=	${SRCS_DIR}/ft_putendl_fd.c
SRCS +=	${SRCS_DIR}/ft_putnbr_fd.c
SRCS +=	${SRCS_DIR}/ft_putstr_fd.c
SRCS +=	${SRCS_DIR}/ft_split.c
SRCS +=	${SRCS_DIR}/ft_strjoin.c
SRCS +=	${SRCS_DIR}/ft_strmapi.c
SRCS +=	${SRCS_DIR}/ft_strtrim.c
SRCS +=	${SRCS_DIR}/ft_substr.c
SRCS +=	${SRCS_DIR}/ft_striteri.c
SRCS +=	${SRCS_DIR}/ft_lstnew_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstadd_front_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstsize_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstlast_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstadd_back_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstdelone_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstclear_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstiter_bonus.c
SRCS +=	${SRCS_DIR}/ft_lstmap_bonus.c

SRCS += ${PRINTF_DIR}/ft_printf.c
SRCS += ${PRINTF_DIR}/ft_print_c.c
SRCS += ${PRINTF_DIR}/ft_print_d.c
SRCS += ${PRINTF_DIR}/ft_print_p.c
SRCS += ${PRINTF_DIR}/ft_print_s.c
SRCS += ${PRINTF_DIR}/ft_print_u.c
SRCS += ${PRINTF_DIR}/ft_print_x.c
SRCS += ${PRINTF_DIR}/ft_put_hex.c
SRCS += ${PRINTF_DIR}/ft_putnbr.c
SRCS += ${PRINTF_DIR}/ft_put_ptr.c
SRCS += ${PRINTF_DIR}/ft_putunbr.c

# HEADERS #

HEADERS_DIR := includes

HEADERS += ${HEADERS_DIR}/libft.h
HEADERS += ${HEADERS_DIR}/ft_printf.h

# OBJECTS #

OBJS := $(patsubst %.c, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
