# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:35:40 by gbazin            #+#    #+#              #
#    Updated: 2024/06/06 14:11:28 by gbazin           ###   ########.fr        #
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

ADDITIONAL =    ft_itoa.c 
ADDITIONAL +=	ft_putchar_fd.c 
ADDITIONAL +=	ft_putendl_fd.c
ADDITIONAL +=	ft_putnbr_fd.c
ADDITIONAL +=	ft_putstr_fd.c
ADDITIONAL +=	ft_split.c
ADDITIONAL +=	ft_strjoin.c
ADDITIONAL +=	ft_strmapi.c
ADDITIONAL +=	ft_strtrim.c
ADDITIONAL +=	ft_substr.c
ADDITIONAL +=	ft_striteri.c

BONUS =		ft_lstnew_bonus.c
BONUS +=	ft_lstadd_front_bonus.c
BONUS +=	ft_lstsize_bonus.c
BONUS +=	ft_lstlast_bonus.c
BONUS +=	ft_lstadd_back_bonus.c
BONUS +=	ft_lstdelone_bonus.c
BONUS +=	ft_lstclear_bonus.c
BONUS +=	ft_lstiter_bonus.c
BONUS +=	ft_lstmap_bonus.c

SRCS = ${LIBC} ${ADDITIONAL}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
		ar -rsc ${NAME} ${OBJS}

bonus:    ${OBJSALL}
		ar -rsc ${NAME} ${OBJSALL}

all:     ${NAME}

clean:
		rm -f ${OBJSALL}

fclean:    clean;
		rm -f ${NAME}

re:    fclean all

.PHONY: all clean fclean re bonus