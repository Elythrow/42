# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:35:40 by gbazin            #+#    #+#              #
#    Updated: 2024/11/25 17:54:08 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = 	ft_atoi.c
LIBC +=	ft_bzero.c
LIBC +=	ft_calloc.c
LIBC +=	ft_isalnum.c
LIBC +=	ft_isalpha.c
LIBC +=	ft_isascii.c
LIBC +=	ft_isdigit.c
LIBC +=	ft_isprint.c
LIBC +=	ft_memchr.c
LIBC +=	ft_memcmp.c
LIBC +=	ft_memcpy.c
LIBC +=	ft_memmove.c
LIBC +=	ft_memset.c
LIBC +=	ft_strchr.c
LIBC +=	ft_strdup.c
LIBC +=	ft_strlcat.c
LIBC +=	ft_strlcpy.c
LIBC +=	ft_strlen.c
LIBC +=	ft_strncmp.c
LIBC +=	ft_strnstr.c
LIBC +=	ft_strrchr.c
LIBC +=	ft_tolower.c
LIBC +=	ft_toupper.c
LIBC += ft_itoa.c 
LIBC +=	ft_putchar_fd.c 
LIBC +=	ft_putendl_fd.c
LIBC +=	ft_putnbr_fd.c
LIBC +=	ft_putstr_fd.c
LIBC +=	ft_split.c
LIBC +=	ft_strjoin.c
LIBC +=	ft_strmapi.c
LIBC +=	ft_strtrim.c
LIBC +=	ft_substr.c
LIBC +=	ft_striteri.c
LIBC +=	ft_lstnew_bonus.c
LIBC +=	ft_lstadd_front_bonus.c
LIBC +=	ft_lstsize_bonus.c
LIBC +=	ft_lstlast_bonus.c
LIBC +=	ft_lstadd_back_bonus.c
LIBC +=	ft_lstdelone_bonus.c
LIBC +=	ft_lstclear_bonus.c
LIBC +=	ft_lstiter_bonus.c
LIBC +=	ft_lstmap_bonus.c

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
		ar -rsc ${NAME} ${OBJS}

all:     ${NAME}

clean:
		rm -f ${OBJS}

fclean:    clean;
		rm -f ${NAME}

re:    fclean all

.PHONY: all clean fclean re bonus