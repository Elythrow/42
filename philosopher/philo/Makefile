# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:50:23 by gbazin            #+#    #+#              #
#    Updated: 2025/06/25 11:52:34 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := philo

# COMPILATION #

CC := cc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra

# SOURCES #

SRCS += main.c
SRCS += utils.c
SRCS += utiles_2.c
SRCS += routines.c

# HEADERS #

HEADERS += philo.h

all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all