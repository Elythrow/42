# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 15:58:44 by gbazin            #+#    #+#              #
#    Updated: 2026/01/05 18:19:48 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := violence

# COMPILATION #

CC := c++

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
CFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp
SRCS += Weapon.cpp
SRCS += HumanA.cpp
SRCS += HumanB.cpp

# OBJECTS #

OBJS := $(patsubst %.cpp, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus