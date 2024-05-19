NAME = ft_display_file

SRC = main.c

OFILES = main.o

CFLAGS = -Wall -Werror -Wextra

CC = cc

all : $(NAME)


$(NAME) :
	${CC} ${CFLAGS} -c $(SRC)
	${CC} -o $(NAME) $(OFILES)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
