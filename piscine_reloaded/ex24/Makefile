SRCS += srcs/ft_putchar.c
SRCS +=	srcs/ft_putstr.c
SRCS +=	srcs/ft_strcmp.c
SRCS +=	srcs/ft_strlen.c
SRCS +=	srcs/ft_swap.c

INCLUDES = includes/

CFLAGS = -Wall -Werror -Wextra

CC = cc

NAME = libft.a

OBJS = ${SRCS:.c=.o}

all : ${OBJS}
	ar -rc ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
